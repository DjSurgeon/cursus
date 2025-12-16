## **Índice**

  - [Requisitos obligatorios](https://www.google.com/search?q=%23requisitos-obligatorios)
      - [Prompt e historial](https://www.google.com/search?q=%23prompt-e-historial)
      - [Ejecución de comandos externos](https://www.google.com/search?q=%23ejecucion-de-comandos-externos)
      - [Manejo de señales](https://www.google.com/search?q=%23manejo-de-se%C3%B1ales)
      - [Comillas y expansión de variables](https://www.google.com/search?q=%23comillas-y-expansion-de-variables)
      - [Redirecciones de E/S](https://www.google.com/search?q=%23redirecciones-de-es)
      - [Pipes (`|`)](https://www.google.com/search?q=%23pipes)
      - [Builtins obligatorios](https://www.google.com/search?q=%23builtins-obligatorios)
      - [Comentarios y limitaciones](https://www.google.com/search?q=%23comentarios-y-limitaciones)
  - [Buenas prácticas de implementación](https://www.google.com/search?q=%23buenas-practicas-de-implementacion)
      - [Arquitectura modular](https://www.google.com/search?q=%23arquitectura-modular)
      - [Gestión de memoria](https://www.google.com/search?q=%23gestion-de-memoria)
      - [Manejo de descriptores](https://www.google.com/search?q=%23manejo-de-descriptores)
      - [Evitar globales innecesarios](https://www.google.com/search?q=%23evitar-globales-innecesarios)
      - [Cumplimiento de la Norma](https://www.google.com/search?q=%23cumplimiento-de-la-norma)
      - [Pruebas unitarias y de integración](https://www.google.com/search?q=%23pruebas-unitarias-y-de-integracion)
  - [Herramientas de depuración](https://www.google.com/search?q=%23herramientas-de-depuracion)
      - [Valgrind](https://www.google.com/search?q=%23valgrind)
      - [GDB](https://www.google.com/search?q=%23gdb)
      - [lsof](https://www.google.com/search?q=%23lsof)
      - [Difusión y comparación con Bash](https://www.google.com/search?q=%23difusion-y-comparacion-con-bash)
  - [Ejemplos clave](https://www.google.com/search?q=%23ejemplos-clave)
      - [Expansión de variables](https://www.google.com/search?q=%23expansion-de-variables)
      - [Redirecciones](https://www.google.com/search?q=%23redirecciones)
      - [Pipes](https://www.google.com/search?q=%23pipes-1)
      - [Errores comunes](https://www.google.com/search?q=%23errores-comunes)

-----

## **Requisitos obligatorios**

### **Prompt e historial**

La shell debe mostrar un **prompt** y leer líneas de entrada de forma interactiva. Se sugiere usar la biblioteca **`readline()`** para la edición de línea y el historial, y **`add_history()`** para guardar cada comando ingresado. Sin embargo, `readline()` puede tener fugas de memoria inherentes. Como alternativa, se puede usar **`getline()`** (POSIX) o bibliotecas ligeras como **Linenoise** (`≈850` líneas de código), que ofrecen una funcionalidad similar sin dependencias pesadas. En cualquier caso, es crucial liberar correctamente la memoria asignada a la línea leída. También se recomienda verificar que la shell libere todos los recursos y salga limpiamente al cerrar (por ejemplo, con `Ctrl-D`).

### **Ejecución de comandos externos**

La shell debe localizar y ejecutar ejecutables externos basándose en la variable de entorno **`PATH`** o mediante una ruta absoluta/relativa. Para ello, se deben usar llamadas al sistema como **`fork()`**, **`execve()`**, y **`wait()`** (o sus variantes) después de `fork()`. Es una buena práctica validar la existencia del ejecutable con **`access(path, X_OK)`** antes de llamar a `execve`. Si el comando no se encuentra, la shell debe mostrar un mensaje de "comando no encontrado" (por ejemplo, usando `perror()` o escribiendo directamente en `stderr`), y no debe terminar abruptamente.

### **Manejo de señales**

En el modo interactivo, la shell debe interceptar señales de control para emular el comportamiento de `bash`.

  - **`Ctrl-C`** debe cancelar la línea actual y mostrar un nuevo prompt.
  - **`Ctrl-D`** (EOF) debe cerrar la shell.
  - **`Ctrl-\`** debe ser ignorado.

Para esto, se configuran manejadores con **`sigaction()`**. Típicamente, **`SIGINT`** se asigna a un manejador propio que limpia el prompt, y **`SIGQUIT`** se asigna a **`SIG_IGN`**. Se recomienda usar la bandera **`SA_RESTART`** para reanudar llamadas al sistema interrumpidas. El enunciado del proyecto permite solo una variable global de tipo entero para comunicar el número de señal recibida, y otras estructuras globales deben evitarse. Una implementación efectiva instala estos manejadores al iniciar la shell.

### **Comillas y expansión de variables**

La shell debe manejar las comillas de forma correcta, similar a `bash`.

  - **Comillas simples (`'...'`)** impiden cualquier interpretación de los caracteres internos. Por ejemplo, `echo '\$VAR'` debe imprimir literalmente `$VAR`.
  - **Comillas dobles (`"..."`)** impiden la interpretación, excepto para la expansión de variables (`$`). Por ejemplo, `echo "\$VAR"` debe reemplazar `$VAR` por su valor.

Además, la shell debe implementar la **expansión de variables de entorno**. Esto se puede lograr obteniendo el valor de la variable con **`getenv`** o manteniendo una copia propia del entorno. También debe implementarse la expansión especial de **`\$?`**, que se sustituye por el código de retorno del último `pipeline` ejecutado.

  - **Ejemplo**: Si un usuario ejecuta `export NOMBRE="42School"` y luego `echo "Hola \$NOMBRE"`, la salida debe ser `Hola 42School`. En contraste, `echo 'Hola \$NOMBRE'` debe mostrar `Hola \$NOMBRE`.

### **Redirecciones de E/S**

La shell debe soportar los operadores de redirección **`<`**, **`>`**, **`<<`**, y **`>>`**.

  - **`< archivo`**: Redirige la entrada estándar (`stdin`) desde un archivo. Se usan `open(file, O_RDONLY)` y `dup2(fd, STDIN_FILENO)`.
  - **`> archivo`**: Redirige la salida estándar (`stdout`) a un archivo, sobrescribiéndolo. Se usa `open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644)` y `dup2` a `STDOUT`.
  - **`>> archivo`**: Similar a `> archivo`, pero abre el archivo con `O_APPEND` para añadir al final.
  - **`<<DELIM` (heredoc)**: La shell debe leer líneas hasta que se encuentre `DELIM` y proveer ese texto como `stdin` del comando, sin guardar esas líneas en el historial.

En la implementación, es importante usar **`dup2()`** para reasignar `stdin`/`stdout` antes de ejecutar el comando, y luego **cerrar el descriptor original**. También es crucial cerrar todos los descriptores no utilizados en cada proceso para evitar fugas de archivos. El documento de 42 destaca la importancia de configurar los descriptores antes de ejecutar el comando.

### **Pipes (`|`)**

Cada `pipe` conecta la salida estándar de un comando con la entrada estándar del siguiente. Para implementar una serie de comandos como `cmd1 | cmd2 | cmd3`, se deben crear tantos `pipes` como conectores haya, utilizando la llamada al sistema **`pipe()`**. Luego, para cada comando, se debe duplicar el extremo de lectura o escritura correspondiente con **`dup2()`**. Por ejemplo, para `ls | grep X`, en el proceso del primer comando se duplica el extremo de escritura a `STDOUT` y se cierra el extremo de lectura. En el segundo comando, se duplica el extremo de lectura a `STDIN` y se cierra el extremo de escritura. Es fundamental cerrar los descriptores innecesarios para evitar bloqueos. Esta técnica de preparar los `pipes` con antelación está alineada con la solución recomendada por 42.

### **Builtins obligatorios**

La shell debe implementar los siguientes comandos internos sin opciones adicionales (excepto `echo`):

  - **`echo [-n]`**: Imprime sus argumentos en la pantalla, sin un salto de línea final si se usa la opción `-n`.
  - **`cd <ruta>`**: Cambia el directorio de trabajo usando **`chdir()`**. Debe manejar casos típicos como `cd` sin argumentos y errores de permisos.
  - **`pwd`**: Muestra el directorio actual usando **`getcwd()`**.
  - **`export VAR=valor`**: Añade o modifica la variable de entorno `VAR`. Se debe mantener un arreglo de *strings* para el entorno interno.
  - **`unset VAR`**: Elimina la variable `VAR` del entorno interno.
  - **`env`**: Lista todas las variables de entorno, imprimiendo el arreglo completo.
  - **`exit [n]`**: Sale de la shell, opcionalmente con un código de retorno `n`.

Para cada *builtin*, es importante verificar los casos de borde (por ejemplo, `cd` sin argumento) y usar las llamadas al sistema adecuadas.

### **Comentarios y limitaciones**

La shell no debe interpretar otros caracteres especiales que no estén explícitamente solicitados en el enunciado (por ejemplo, `;` o *globbing*). Las comillas sin cerrar deben considerarse un error de sintaxis y la shell no debe colgarse, 110. Cualquier característica adicional, como los operadores lógicos `&&` o `||` o *wildcards*, es opcional y solo se evaluará si la parte obligatoria es perfecta. El enunciado enfatiza en apegarse estrictamente a los requisitos. Si hay dudas, el comportamiento de `bash` debe servir como referencia.

-----

## **Buenas prácticas de implementación**

### **Arquitectura modular**

Se recomienda dividir el programa en fases claras:

  - **`Lexer`**: para la tokenización de la entrada.
  - **`Parser`**: para construir un árbol de sintaxis o estructuras de datos para los comandos.
  - **`Expansor`**: para manejar la expansión de variables y comillas.
  - **`Ejecutor`**: para lanzar los procesos.
    Esta arquitectura facilita la extensión y depuración del código. En los proyectos de 42, es común que se asigne el desarrollo del *parser* a una persona y el del *executor* a otra. Si se implementan operadores lógicos, se aconseja usar una estructura de árbol binario para representarlos.

### **Gestión de memoria**

Cada asignación de memoria con **`malloc`** o **`strdup`** debe ser liberada posteriormente. Se deben usar estructuras dinámicas (como listas enlazadas o arreglos dinámicos) para guardar argumentos, y liberarlas cuando ya no se necesiten (por ejemplo, con funciones como `free_tokens()` o `free_commands()`). La programación defensiva es clave: se debe comprobar el valor de retorno de las llamadas (`NULL`) y, en caso de fallos del sistema, limpiar los recursos posibles antes de abortar. Para asegurar que no haya fugas, es vital usar **Valgrind** y **GDB** regularmente durante el desarrollo. Un método eficaz es ejecutar la shell con `valgrind --leak-check=full --track-fds=yes ./minishell` después de cada cambio significativo para corregir las fugas detectadas.

### **Manejo de descriptores**

Siempre se deben cerrar los descriptores de archivos o `pipes` que no se estén usando, con la función **`close()`**. Por ejemplo, después de usar `dup2()`, tanto los descriptores `fd[0]` como `fd[1]` deben ser cerrados en el padre y en los hijos, según sea apropiado. Herramientas como **`lsof`** (`lsof -p <PID>`) pueden ser de gran ayuda para verificar que no queden archivos abiertos inesperadamente.

### **Evitar globales innecesarios**

Aparte de la única variable global permitida para el manejo de señales, es preferible pasar estructuras de estado (como el entorno o el último código de salida) a través de punteros o de un contexto. Esto mejora la modularidad del código y previene efectos secundarios no deseados.

### **Cumplimiento de la Norma**

El código debe seguir la convención del proyecto (estilo 42), compilar sin advertencias usando las banderas `-Wall -Wextra -Werror`, y la **Makefile** debe incluir las reglas obligatorias (`all`, `clean`, `fclean`, `re`, `bonus`). También es importante asegurarse de que no queden archivos temporales ni permisos extraños. El analizador **norminette** debe pasar sin errores.

### **Pruebas unitarias y de integración**

Aunque no es un requisito de entrega, se recomienda encarecidamente crear **pruebas automatizadas** (mediante *scripts* de Bash) que comparen el comportamiento de la minishell con el de `bash`. Se pueden escribir *scripts* que ejecuten varios comandos con redirecciones y `pipes`, y luego comparar la salida de la minishell con la de `bash` usando `diff`. La comunidad de 42 ofrece *testers* avanzados, como el de Zstenger, con cientos de casos de prueba. Sin embargo, no hay que confiar ciegamente en ellos; es mejor diseñar casos propios, especialmente para escenarios límite como símbolos sin cerrar, comandos inválidos o un entorno vacío.

-----

## **Herramientas de depuración**

### **Valgrind**

Es una herramienta esencial para detectar fugas y errores de memoria. Se recomienda ejecutarla con el comando `valgrind --leak-check=full --show-leak-kinds=all ./minishell`. **Valgrind** puede reportar bloques de memoria no liberados y descriptores de archivos abiertos si se usa la opción `--track-fds=yes`. Se aconseja repetir esta verificación después de cada nueva funcionalidad para asegurar la integridad del código.

### **GDB**

Compilar el código con la bandera `-g` permite usar **GDB** para seguir la ejecución paso a paso. Es muy útil para entender el flujo del programa y localizar fallos como punteros `NULL` o comportamientos inesperados después de un `fork`. Se pueden establecer puntos de interrupción (`breakpoints`) en funciones críticas (`execve`, redirecciones, manejadores de señales) y usar `backtrace` para analizar los `segfaults`. La combinación de **GDB**, **Valgrind** y mensajes de depuración (`print statements`) es muy efectiva para rastrear cada asignación y liberación de memoria.

### **lsof**

**`lsof`** lista los archivos abiertos de un proceso y es útil para detectar fugas de descriptores de archivos (`fd`). Mientras la shell se ejecuta, el comando `lsof -p <PID>` mostrará qué archivos y `pipes` están abiertos. Si los descriptores no vuelven a su estado esperado después de una ejecución, significa que algo no se cerró correctamente.

### **Difusión y comparación con Bash**

Para verificar la exactitud funcional, se pueden ejecutar las mismas series de comandos en `bash` y en la minishell, y luego comparar sus salidas con **`diff`**. También es importante comparar los códigos de salida (`\$?`). Herramientas como los *testers* de 42 pueden generar diferencias automáticamente. Es una buena práctica tener una consola de `bash` abierta para probar manualmente los casos.

-----

## **Ejemplos clave**

### **Expansión de variables**

```bash
$ export NOMBRE="42School"
$ echo Hola $NOMBRE
Hola 42School
$ echo 'Hola $NOMBRE'
Hola $NOMBRE
```

En este ejemplo, la primera línea asigna el valor "42School" a la variable `NOMBRE`. La segunda línea muestra la expansión de la variable porque `$NOMBRE` no está entre comillas simples. La tercera línea usa comillas simples, lo que evita la expansión. El código de retorno del último comando se almacena en `\$?`: si se ejecuta `echo $?` justo después, la salida sería `0` (éxito).

### **Redirecciones**

```bash
$ ls -1 > listado.txt  # Redirige stdout a un archivo (lo sobrescribe)
$ cat < listado.txt    # Lee listado.txt como stdin
$ echo "Fin" >> listado.txt # Añade "Fin" al final de listado.txt
```

Estos comandos ilustran cómo `>` abre un archivo en modo de escritura (`O_CREAT | O_TRUNC`), `<` lo abre en modo de solo lectura (`O_RDONLY`), y `>>` lo abre en modo de anexo (`O_APPEND`). En el código C, cada redirección requiere un **`open()`** seguido de un **`dup2()`**.

### **Pipes**

```bash
$ cat archivo.txt | grep "hola" | wc -l > cuenta.txt
```

En este ejemplo, la salida de `cat` se envía a `grep` a través de un `pipe`. La salida de `grep` se redirige a `wc -l` a través de otro `pipe`. Finalmente, la salida de `wc -l` se guarda en `cuenta.txt` mediante una redirección. La shell logra esto creando dos `pipes` (`pipe(fd1)`, `pipe(fd2)`) y duplicando los descriptores con **`dup2()`** en cada proceso. Los extremos no utilizados de los `pipes` deben cerrarse.

### **Errores comunes**

  - **Comillas sin cerrar**: Si un usuario escribe `echo "hola` sin cerrar las comillas, la shell debe detectar el error de sintaxis y mostrar un mensaje, sin colgarse.
  - **Comando desconocido**: Un comando como `foobar` debe producir un mensaje como `minishell: foobar: command not found`.
  - **`cd` sin argumento**: Por convención, debe cambiar al directorio *home* del usuario (`$HOME`).
  - **`export VAR` (sin `=`)**: El enunciado no pide manejar esta variante. Se puede considerar un error o simplemente no hacer nada, lo importante es que la shell no se cuelgue (`crash`).