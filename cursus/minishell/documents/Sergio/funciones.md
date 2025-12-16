# Explicación de las Funciones de Minishell

## Tabla de Contenidos

1.  [Introducción](https://www.google.com/search?q=%23introduccion)
2.  [Librería de E/S Estándar (`stdio.h`)](https://www.google.com/search?q=%23libreria-de-es-estandar-stdioh)
      - [`printf`](https://www.google.com/search?q=%23printf)
3.  [Librería Estándar (`stdlib.h`)](https://www.google.com/search?q=%23libreria-estandar-stdlibh)
      - [`malloc`, `free`, `exit`, `getenv`](https://www.google.com/search?q=%23malloc-free-exit-getenv)
4.  [Funciones de Readline (`readline/readline.h`, `readline/history.h`)](https://www.google.com/search?q=%23funciones-de-readline-readlinereadlineh-readlinehistoryh)
      - [`readline`, `rl_clear_history`, `rl_on_new_line`, `rl_replace_line`, `rl_redisplay`, `add_history`](https://www.google.com/search?q=%23readline-rl_clear_history-rl_on_new_line-rl_replace_line-rl_redisplay-add_history)
5.  [Señales (`signal.h`)](https://www.google.com/search?q=%23senales-signalh)
      - [`signal`, `sigaction`, `sigemptyset`, `sigaddset`, `kill`](https://www.google.com/search?q=%23signal-sigaction-sigemptyset-sigaddset-kill)
6.  [Control de Procesos y Archivos (`unistd.h`, `sys/types.h`, `sys/wait.h`, `fcntl.h`, `sys/stat.h`)](https://www.google.com/search?q=%23control-de-procesos-y-archivos-unistdh-systypesh-syswaith-fcntlh-sysstath)
      - [`fork`, `wait`, `waitpid`, `wait3`, `wait4`, `execve`](https://www.google.com/search?q=%23fork-wait-waitpid-wait3-wait4-execve)
      - [`write`, `access`, `open`, `read`, `close`](https://www.google.com/search?q=%23write-access-open-read-close)
      - [`getcwd`, `chdir`, `stat`, `lstat`, `fstat`, `unlink`](https://www.google.com/search?q=%23getcwd-chdir-stat-lstat-fstat-unlink)
      - [`dup`, `dup2`, `pipe`](https://www.google.com/search?q=%23dup-dup2-pipe)
7.  [Funciones de Directorio (`dirent.h`)](https://www.google.com/search?q=%23funciones-de-directorio-direnth)
      - [`opendir`, `readdir`, `closedir`](https://www.google.com/search?q=%23opendir-readdir-closedir)
8.  [Funciones de Terminal y Dispositivos (`unistd.h`, `sys/ioctl.h`, `termios.h`, \`termcap/curses)](https://www.google.com/search?q=%23funciones-de-terminal-y-dispositivos-unistdh-sysioctlh-termiosh-termcapcurses)
      - [`isatty`, `ttyname`, `ttyslot`, `ioctl`](https://www.google.com/search?q=%23isatty-ttyname-ttyslot-ioctl)
      - [`tcsetattr`, `tcgetattr`](https://www.google.com/search?q=%23tcsetattr-tcgetattr)
      - [`tgetent`, `tgetflag`, `tgetnum`, `tgetstr`, `tgoto`, `tputs`](https://www.google.com/search?q=%23tgetent-tgetflag-tgetnum-tgetstr-tgoto-tputs)
9.  [Manejo de Errores (`errno.h` y relacionados)](https://www.google.com/search?q=%23manejo-de-errores-errnoh-y-relacionados)
      - [`strerror`, `perror`](https://www.google.com/search?q=%23strerror-perror)
10. [Conclusión](https://www.google.com/search?q=%23conclusion)

-----

## Introducción

Esta documentación (v.01) describe las **funciones de nivel de sistema** relevantes para **minishell**, agrupadas por las librerías o encabezados de los que provienen. Cada sección comienza con una descripción general de alto nivel del propósito de la librería y los conceptos relevantes, y luego explica cada función con ejemplos de **uso correcto** y errores comunes de **uso incorrecto**. El objetivo es proporcionar una comprensión más clara de la programación de bajo nivel en C y las interacciones del sistema operativo, específicamente para un entorno similar a un shell.

-----

## Librería de E/S Estándar (`stdio.h`)

### Visión General

  - La librería `stdio.h` proporciona funciones para:
      - Leer desde la **entrada estándar** (`stdin`)
      - Escribir en la **salida estándar** (`stdout`)
      - Impresión formateada (`printf`, `fprintf`, etc.)

### `printf`

  - **Encabezado**: `#include <stdio.h>`
  - **Descripción**: Imprime la salida formateada en `stdout`.

**Explicación Detallada**:

  - **Formato**: `printf` utiliza especificadores de formato (como `%d`, `%s`) para formatear diferentes tipos de datos.
  - **Valor de Retorno**: Retorna el número total de caracteres escritos, o un valor negativo si ocurre un error.
  - **Buffer**: Generalmente, se almacena en el buffer por línea en un terminal; se vacía con un salto de línea o cuando el buffer se llena.
  - **Errores Comunes**:
      - Especificadores de formato incorrectos (por ejemplo, usar `%d` para un `double`).
      - No incluir un salto de línea (puede hacer que la salida en el buffer no aparezca de inmediato).

**Uso Correcto**:

```c
#include <stdio.h>

int main(void) {
    printf("Hola, %s!\n", "Mundo"); // usa los especificadores de formato correctos
    return 0;
}
```

**Uso Incorrecto**:

```c
printf("Número: " 10); // Falta el especificador de formato --> error
```

**Razón**: El compilador no puede analizar `(\"Número: \" 10)` correctamente, causando un comportamiento inesperado.

-----

## Librería Estándar (`stdlib.h`)

### Visión General

  - **Manejo de memoria**: `malloc`, `free`, etc.
  - **Terminación de procesos**: `exit`
  - **Variables de entorno**: `getenv`

### `malloc, free, exit, getenv`

#### `malloc`

  - **Encabezado**: `#include <stdlib.h>`
  - **Descripción**: Asigna dinámicamente el número de bytes solicitado y retorna un puntero a la memoria asignada.
  - **Explicación Detallada**:
      - **Asignación de Memoria**: Reserva un bloque de memoria contiguo en el heap.
      - **Inicialización**: El contenido de la memoria asignada no está **inicializado**.
      - **Fallo**: Retorna `NULL` si la asignación falla; siempre verifica.
      - **Alineación**: Generalmente está alineado de manera adecuada para cualquier tipo de dato.

**Uso Correcto**:

```c
int *arr = malloc(10 * sizeof(int));
if (!arr) {
    perror("Fallo al asignar");
    exit(EXIT_FAILURE);
}
```

**Razón**: Siempre verifica el valor de retorno de `malloc` para `NULL`.

#### `free`

  - **Encabezado**: `#include <stdlib.h>`
  - **Descripción**: Libera un bloque de memoria previamente asignado.
  - **Explicación Detallada**:
      - **Propiedad**: Solo libera la memoria que fue asignada por `malloc`/`calloc`/`realloc`.
      - **Doble Liberación**: Llamar a `free` en el mismo puntero más de una vez conduce a un comportamiento indefinido.
      - **Después de Liberar**: El puntero se vuelve inválido; no lo desreferencies.

**Uso Correcto**:

```c
free(arr);
```

**Uso Incorrecto**:

```c
free(arr);
free(arr); // Doble liberación -> comportamiento indefinido
```

#### `exit`

  - **Descripción**: Termina el proceso actual inmediatamente, retornando un código de estado.
  - **Explicación Detallada**:
      - **Limpieza**: Llama a las funciones registradas con `atexit`, vacía los buffers de E/S.
      - **Códigos de Salida**: Convencionalmente `EXIT_SUCCESS (0)` significa éxito, `EXIT_FAILURE` significa error.

<!-- end list -->

```c
exit(EXIT_SUCCESS);
```

#### `getenv`

  - **Descripción**: Recupera el valor de una variable de entorno.
  - **Explicación Detallada**:
      - **Retorno**: Retorna un puntero a una cadena en la lista de entorno.
      - **Mutable?**: Algunas implementaciones permiten modificar las variables de entorno a través de `setenv`, pero el puntero de `getenv` no debe ser liberado.
      - **Uso**: Se usa a menudo para obtener `PATH`, `HOME`, etc.

<!-- end list -->

```c
char *path = getenv("PATH");
if (path) {
    printf("PATH: %s\n", path);
}
```

-----

## Funciones de Readline (`readline/readline.h`, `readline/history.h`)

### Visión General

La **librería Readline** proporciona funcionalidades para la edición de la línea de comandos y la gestión del historial. Es ampliamente utilizada en programas interactivos, particularmente en shells, para permitir a los usuarios editar comandos de manera cómoda, gestionar historiales de comandos y mejorar la usabilidad.

### `readline, rl_clear_history, rl_on_new_line, rl_replace_line, rl_redisplay, add_history`

### Funciones Explicadas

#### `readline`

  - **Encabezado**: `#include <readline/readline.h>`
  - **Descripción**: Lee la entrada del usuario desde la entrada estándar con capacidades de edición mejoradas.
  - **Comportamiento**:
      - Soporta la edición de línea (por ejemplo, movimiento del cursor, borrado).
      - Retorna una cadena dinámicamente asignada, que debe ser liberada manualmente por quien la llama.
      - Retorna `NULL` al llegar a EOF (`Ctrl+D`).

**Ejemplo de Uso Correcto:**

```c
#include <readline/readline.h>
#include <stdlib.h>

int main(void) {
    char *input = readline("minishell> ");
    if (!input) {
        printf("Se recibió EOF, saliendo.\n");
        exit(EXIT_SUCCESS);
    }
    printf("Ingresaste: %s\n", input);
    free(input);
    return 0;
}
```

**Errores Comunes:**

  - Olvidar liberar la memoria asignada por `readline`.
  - No verificar el valor de retorno `NULL` (manejo de EOF).

#### `add_history`

  - **Encabezado**: `#include <readline/history.h>`
  - **Descripción**: Añade una línea a la lista del historial, permitiendo su recuperación a través de las teclas de flecha en llamadas subsiguientes.

**Ejemplo de Uso Correcto:**

```c
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

int main(void) {
    char *input = readline("minishell> ");
    if (input && *input) {
        add_history(input);
    }
    free(input);
    return 0;
}
```

**Errores Comunes:**

  - Añadir cadenas vacías o nulas al historial.

#### `rl_clear_history`

  - **Encabezado**: `#include <readline/history.h>`
  - **Descripción**: Borra todas las entradas en el historial, típicamente usado al reiniciar o restablecer el historial de entrada de comandos.

**Ejemplo de Uso Correcto:**

```c
#include <readline/history.h>

void clear_shell_history(void) {
    rl_clear_history();
    printf("Historial borrado exitosamente.\n");
}
```

#### `rl_on_new_line`

  - **Encabezado**: `#include <readline/readline.h>`
  - **Descripción**: Informa a la librería readline que el cursor se ha movido a una nueva línea, usado frecuentemente después del manejo de señales para reposicionar el cursor correctamente.

**Ejemplo de Uso Correcto (Manejo de Señales):**

```c
#include <readline/readline.h>
#include <signal.h>

void sigint_handler(int sig) {
    rl_on_new_line();
    rl_replace_line("", 0);
    rl_redisplay();
}

int main(void) {
    signal(SIGINT, sigint_handler);
    char *input;
    while ((input = readline("minishell> "))) {
        free(input);
    }
    return 0;
}
```

#### `rl_replace_line`

  - **Encabezado**: `#include <readline/readline.h>`
  - **Descripción**: Reemplaza el contenido del buffer de readline con la cadena dada.

**Ejemplo de Uso Correcto:**

```c
#include <readline/readline.h>

void replace_current_line(const char *new_line) {
    rl_replace_line(new_line, 0);
    rl_redisplay();
}
```

#### `rl_redisplay`

  - **Encabezado**: `#include <readline/readline.h>`
  - **Descripción**: Fuerza a readline a refrescar y redisplayar el buffer de edición actual. Esencial después de modificaciones al buffer o a la posición del cursor.

**Ejemplo de Uso Correcto:**

```c
#include <readline/readline.h>

void refresh_display(void) {
    rl_redisplay();
}
```

**Mejores Prácticas Generales**:

  - Siempre maneja la asignación de memoria con cuidado (especialmente las cadenas retornadas por `readline`).
  - Gestiona adecuadamente el historial para mejorar la experiencia del usuario.
  - Implementa un manejo de señales exhaustivo para gestionar interrupciones y acciones del usuario de manera elegante.

<!-- end list -->

```c
char *input = readline("myshell> ");
if (input) {
    add_history(input);
    // procesar la entrada
}
```

-----

## Señales (`signal.h`)

### Visión General

**¿Qué son las señales?**
Las señales son **interrupciones de software** enviadas a un proceso para indicar eventos como `Ctrl+C` (`SIGINT`), solicitudes de terminación (`SIGTERM`), fallos de segmentación (`SIGSEGV`), etc. Cuando llega una señal, la ejecución normal se interrumpe y un **manejador de señales** puede tomar el control si se ha configurado uno.

### `signal, sigaction, sigemptyset, sigaddset, kill`

#### `signal`

  - **Descripción**: Instala una función manejadora simple para `sig`.
  - **Detalles**:
      - Algunas señales (por ejemplo, `SIGKILL`, `SIGSTOP`) no pueden ser capturadas o ignoradas.
      - `signal` es menos flexible que `sigaction`.

<!-- end list -->

```c
signal(SIGINT, my_handler);
```

#### `sigaction`

  - **Descripción**: Una forma más configurable de establecer manejadores con banderas y máscaras.
  - **Detalles**:
      - Permite bloquear otras señales mientras el manejador se está ejecutando.
      - `sa_sigaction` se puede usar para manejadores avanzados que necesitan información extra.

<!-- end list -->

```c
struct sigaction sa;
sa.sa_handler = my_handler;
sigemptyset(&sa.sa_mask);
sa.sa_flags = 0;
sigaction(SIGINT, &sa, NULL);
```

#### `sigemptyset`

  - **Descripción**: Inicializa un conjunto de señales (`sigset_t`) para excluir todas las señales. Se usa comúnmente antes de añadir señales explícitamente a un conjunto.
  - **Detalles**:
      - Establece el conjunto de señales dado como vacío (no incluye ninguna señal).
      - Un paso esencial antes de manipular máscaras de señales usando `sigaddset`.

<!-- end list -->

```c
#include <signal.h>
#include <stdio.h>

int main(void) {
    sigset_t set;

    if (sigemptyset(&set) == -1) {
        perror("sigemptyset falló");
        return 1;
    }

    // El conjunto de señales ahora está vacío; puedes añadir señales explícitamente
    return 0;
}
```

**Errores Comunes**:
Olvidar inicializar el conjunto de señales antes de añadir señales, lo que conduce a un comportamiento impredecible.
No verificar el valor de retorno para el manejo de errores.

#### `sigaddset`

  - **Descripción**: Añade una señal específica (por ejemplo, `SIGINT`, `SIGTERM`) a un conjunto de señales.
  - **Detalles**:
      - Permite la adición de señales específicas a un conjunto de señales previamente inicializado.
      - Se usa comúnmente para bloquear señales o especificar señales en funciones como `sigaction`.

**Ejemplo de Uso Correcto**:

```c
#include <signal.h>
#include <stdio.h>

int main(void) {
    sigset_t set;

    if (sigemptyset(&set) == -1) {
        perror("sigemptyset falló");
        return 1;
    }

    if (sigaddset(&set, SIGTERM) == -1) {
        perror("sigaddset falló");
        return 1;
    }

    // SIGTERM ahora está añadida al conjunto; se puede usar con sigaction o sigprocmask
    return 0;
}
```

**Errores Comunes**:
No verificar el valor de retorno de `sigaddset`, lo que podría indicar fallos (por ejemplo, números de señal inválidos).
Intentar usar un conjunto no inicializado con `sigaddset`.

#### `kill`

  - **Descripción**: Envía una señal a un proceso o grupo de procesos especificado por un ID de proceso (PID).
  - **Detalles**:
      - Envía una señal especificada (por ejemplo, `SIGTERM`, `SIGKILL`) al proceso con el PID dado.
      - Si la señal es `0`, no se envía ninguna señal, pero la función realiza una verificación de errores. Se puede usar para verificar si el proceso existe y si el llamante tiene permiso para enviarle señales.

**Ejemplo de Uso Correcto**:

```c
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <PID>\n", argv[0]);
        return 1;
    }

    pid_t pid = atoi(argv[1]);

    if (kill(pid, SIGTERM) == -1) {
        perror("kill falló");
        return 1;
    }

    printf("SIGTERM enviada exitosamente al PID %d\n", pid);
    return 0;
}
```

Ejemplo para Verificar si un Proceso Existe Usando `kill(pid, 0)`:

```c
#include <signal.h>
#include <stdio.h>

int check_process_exists(pid_t pid) {
    if (kill(pid, 0) == 0) {
        printf("El proceso %d existe y es accesible.\n", pid);
        return 1;
    } else {
        perror("La verificación de kill falló");
        return 0;
    }
}

int main(void) {
    pid_t pid_to_check = 12345; // Reemplazar con el PID real
    check_process_exists(pid_to_check);
    return 0;
}
```

**Errores Comunes**:
Enviar señales inapropiadas (por ejemplo, usar `SIGKILL` cuando se prefiere una terminación elegante con `SIGTERM`).
No verificar que el PID sea válido antes de enviar señales.
Malinterpretar `kill(pid, 0)` como el envío de una señal cuando en realidad solo verifica la validez y los permisos del proceso.

**Mejores Prácticas**:
Siempre inicializa correctamente los conjuntos de señales antes de manipularlos.
Maneja los valores de retorno y los errores meticulosamente para asegurar un código robusto.
Usa `kill(pid, 0)` con precaución para verificar la existencia o permisos del proceso.

-----

## Documentación de Funciones de Gestión de Procesos

Este documento describe varias funciones de gestión de procesos, incluyendo sus encabezados, comportamiento detallado, ejemplos de uso correcto, errores comunes y una tabla comparativa de sus características.

Estas funciones residen en varios encabezados:

  - `unistd.h` (funciones estándar POSIX)
  - `sys/wait.h` (espera de procesos)
  - `fcntl.h` (banderas de control de archivos)
  - `sys/stat.h` (estado de archivos)

### `fork, wait, waitpid, wait3, wait4, execve`

#### `fork`

  - **Descripción**: Crea un nuevo proceso hijo.
  - **Detalles**:
      - Retorna `0` al hijo, retorna el PID del hijo al padre, o `-1` en caso de error.
      - El hijo hereda los descriptores de archivo, el entorno, etc., pero tiene su propio PID.

<!-- end list -->

```c
pid_t pid = fork();
if (pid == 0) {
    // hijo
} else if (pid > 0) {
    // padre
} else {
    perror("fork falló");
}
```

## `wait`

**Encabezado:** `#include <sys/wait.h>`

**Descripción:**
Espera a que cualquier proceso hijo termine.

**Detalles:**

  - Suspende el proceso llamante hasta que cualquier proceso hijo se cierre.
  - El estado de terminación del hijo se almacena en el entero de estado proporcionado.
  - Ayuda a prevenir procesos "zombie" recolectando los estados de terminación de los hijos.

**Ejemplo de Uso Correcto:**

```c
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main(void) {
    pid_t pid = fork();

    if (pid == 0) {
        // Proceso hijo
        _exit(0);
    } else if (pid > 0) {
        int status;
        if (wait(&status) == -1)
            perror("wait falló");
        else if (WIFEXITED(status))
            printf("El hijo salió con estado %d\n", WEXITSTATUS(status));
    } else {
        perror("fork falló");
    }

    return 0;
}
```

**Errores Comunes:**

  - Ignorar los valores de retorno.
  - Omitir posibles verificaciones de errores.
  - Interpretar incorrectamente el estado sin usar las macros adecuadas (por ejemplo, `WIFEXITED`, `WEXITSTATUS`).

-----

## `waitpid`

**Encabezado:** `#include <sys/wait.h>`

**Descripción:**
Espera específicamente la terminación de un proceso hijo designado.

**Detalles:**

  - Espera al hijo identificado por su PID.
  - Ofrece control adicional a través de banderas como `WNOHANG` (no bloqueante) o `WUNTRACED`.
  - Se usa para recolectar estados de salida y evitar zombies.

**Ejemplo de Uso Correcto:**

```c
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main(void) {
    pid_t pid = fork();

    if (pid == 0) {
        // Proceso hijo
        sleep(2);
        _exit(0);
    } else if (pid > 0) {
        int status;
        if (waitpid(pid, &status, 0) == -1)
            perror("waitpid falló");
        else if (WIFEXITED(status))
            printf("El hijo %d salió con estado %d\n", pid, WEXITSTATUS(status));
    } else {
        perror("fork falló");
    }

    return 0;
}
```

**Errores Comunes:**

  - Uso incorrecto de banderas (por ejemplo, `WNOHANG`) que causa un comportamiento no deseado.
  - No manejar los valores de retorno y los errores.

-----

## `wait3`

**Encabezado:** `#include <sys/wait.h>`

**Descripción:**
Similar a `wait`, espera a que cualquier proceso hijo y también proporciona estadísticas de uso de recursos.

**Detalles:**

  - Recolecta el uso de la CPU, el consumo de memoria, los cambios de contexto y más en una `struct rusage`.
  - Permite banderas adicionales para un comportamiento de espera personalizado.

**Ejemplo de Uso Correcto:**

```c
#include <sys/wait.h>
#include <sys/resource.h>
#include <unistd.h>
#include <stdio.h>

int main(void) {
    pid_t pid = fork();

    if (pid == 0) {
        // Proceso hijo
        sleep(1);
        _exit(0);
    } else if (pid > 0) {
        int status;
        struct rusage usage;
        if (wait3(&status, 0, &usage) == -1) {
            perror("wait3 falló");
        } else if (WIFEXITED(status)) {
            printf("El hijo salió con estado %d\n", WEXITSTATUS(status));
            printf("Tiempo de CPU de usuario: %ld.%06ld seg\n", usage.ru_utime.tv_sec, usage.ru_utime.tv_usec);
            printf("Tiempo de CPU de sistema: %ld.%06ld seg\n", usage.ru_stime.tv_sec, usage.ru_stime.tv_usec);
        }
    } else {
        perror("fork falló");
    }

    return 0;
}
```

**Errores Comunes:**

  - Interpretar incorrectamente los datos de uso de recursos en `struct rusage`.
  - Descuidar las verificaciones de estado y errores adecuadas.

-----

## `wait4`

**Encabezado:** `#include <sys/wait.h>`

**Descripción:**
Combina las funcionalidades de `waitpid` y `wait3` esperando un proceso hijo específico y proporcionando un seguimiento detallado de los recursos.

**Detalles:**

  - Espera al proceso hijo designado basándose en su PID.
  - Combina la espera específica con la recolección de estadísticas de uso de recursos a través de `struct rusage`.

**Ejemplo de Uso Correcto:**

```c
#include <sys/wait.h>
#include <sys/resource.h>
#include <unistd.h>
#include <stdio.h>

int main(void) {
    pid_t pid = fork();

    if (pid == 0) {
        // Proceso hijo
        sleep(1);
        _exit(0);
    } else if (pid > 0) {
        int status;
        struct rusage usage;
        if (wait4(pid, &status, 0, &usage) == -1) {
            perror("wait4 falló");
        } else if (WIFEXITED(status)) {
            printf("El hijo %d salió con estado %d\n", pid, WEXITSTATUS(status));
            printf("Tiempo de CPU de usuario: %ld.%06ld seg\n", usage.ru_utime.tv_sec, usage.ru_utime.tv_usec);
            printf("Tiempo de CPU de sistema: %ld.%06ld seg\n", usage.ru_stime.tv_sec, usage.ru_stime.tv_usec);
        }
    } else {
        perror("fork falló");
    }

    return 0;
}
```

**Errores Comunes:**

  - Manejo incorrecto o descuido de las estadísticas de uso de recursos.
  - Confundir su uso con `waitpid` y olvidar el parámetro adicional `struct rusage`.

-----

## Tabla de Comparación

| Función | Espera por | ¿PID Específico? | ¿Proporciona Uso de Recursos? | ¿Soporta Banderas? |
|---|---|---|---|---|
| `wait` | Cualquier proceso hijo | No | No | No |
| `waitpid` | Hijo específico | Sí | No | Sí |
| `wait3` | Cualquier proceso hijo | No | Sí | Sí |
| `wait4` | Hijo específico | Sí | Sí | Sí |

**Recomendaciones de Uso:**

  - **Usa `wait`** si simplemente esperas a cualquier hijo sin requerir datos adicionales.
  - **Usa `waitpid`** para esperar a un hijo específico o cuando se necesitan banderas no bloqueantes.
  - **Usa `wait3`** al recuperar estadísticas de uso de recursos para cualquier hijo que termine.
  - **Usa `wait4`** para un monitoreo preciso que involucre tanto la terminación del proceso como las estadísticas de recursos.

-----

## `execve`

**Encabezado:** `#include <unistd.h>`

**Descripción:**
Reemplaza el proceso en ejecución actual con un nuevo programa.

**Detalles:**

  - Requiere una ruta de archivo explícita al nuevo ejecutable, junto con punteros a los argumentos (`argv`) y un array de variables de entorno (`envp`).
  - Si tiene éxito, `execve` nunca retorna; si falla, retorna `-1` y establece `errno`.

**Ejemplo de Uso Correcto:**

```c
#include <unistd.h>
#include <stdio.h>

int main(void) {
    char *argv[] = {"/bin/ls", "-l", NULL};
    char *envp[] = {NULL};

    execve("/bin/ls", argv, envp);

    // Solo se llega aquí si execve falla
    perror("execve falló");
    return 1;
}
```

**Errores Comunes:**

  - Asumir que el proceso continúa ejecutándose después de una llamada exitosa a `execve` (no lo hace).
  - Inicializar incorrectamente los arrays `argv` o `envp` (ambos deben terminar con `NULL`).

**Nota:**
Siempre usa las macros apropiadas (como `WIFEXITED`, `WEXITSTATUS`, `WIFSIGNALED`, etc.) para interpretar el estado de salida de todas las funciones de la familia `wait` para asegurar un manejo de errores robusto y mantener la estabilidad del programa.

-----

## Funciones de E/S de Archivos (`unistd.h`, `fcntl.h`)

### `write, access, open, read, close`

## Visión General

Estas funciones de nivel de sistema facilitan las operaciones de entrada/salida de bajo nivel, permitiendo la interacción directa con descriptores de archivo, la verificación de permisos y la gestión eficiente de los estados de los archivos.

-----

## `write`

**Encabezado:** `#include <unistd.h>`

**Descripción:**
Escribe hasta `count` bytes desde el buffer proporcionado (`buf`) en el descriptor de archivo dado (`fd`).

**Detalles:**

  - Retorna el número de bytes realmente escritos.
  - Puede retornar menos bytes de los solicitados (escrituras parciales).
  - Retorna `-1` en caso de error (establece `errno`).

**Ejemplo de Uso Correcto:**

```c
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(void) {
    int fd = open("output.txt", O_WRONLY | O_CREAT, 0644);
    if (fd == -1) {
        perror("open falló");
        return 1;
    }

    const char *text = "Hola, minishell!\n";
    ssize_t written = write(fd, text, 18);
    if (written == -1)
        perror("write falló");

    close(fd);
    return 0;
}
```

**Errores Comunes:**

  - No manejar las escrituras parciales (menos bytes de los solicitados).
  - Ignorar los valores de retorno y los errores.

## `access`

**Encabezado:** `#include <unistd.h>`

**Descripción:**
Verifica si el proceso llamante tiene permisos (lectura/escritura/ejecución) para un archivo.

**Detalles:**

  - Útil para verificaciones preliminares, pero puede introducir condiciones de carrera TOCTOU (Time-of-Check, Time-of-Use) si se usa incorrectamente.
  - Retorna `0` si tiene éxito (los permisos existen), `-1` en caso contrario.

**Ejemplo de Uso Correcto:**

```c
#include <unistd.h>
#include <stdio.h>

int main(void) {
    if (access("file.txt", R_OK | W_OK) == 0)
        printf("Permisos de lectura/escritura disponibles.\n");
    else
        perror("La verificación de access falló");

    return 0;
}
```

**Errores Comunes:**

  - Depender únicamente de `access` para operaciones críticas de seguridad (posibles condiciones de carrera).
  - No manejar el valor de retorno y el error correctamente.

## `open`

**Encabezado:** `#include <fcntl.h>`

**Descripción:**
Abre o crea un archivo, retornando un descriptor de archivo.

**Detalles:**

  - El descriptor de archivo permite operaciones subsiguientes (`read`, `write`, `close`).
  - Las banderas como `O_RDONLY`, `O_WRONLY`, `O_RDWR`, `O_CREAT`, `O_APPEND` controlan los modos y comportamientos de acceso al archivo.
  - El parámetro de modo establece los permisos para los archivos recién creados.

**Ejemplo de Uso Correcto:**

```c
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(void) {
    int fd = open("example.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open falló");
        return 1;
    }
    // Usar fd...
    close(fd);
    return 0;
}
```

**Errores Comunes:**

  - Parámetro de modo incorrecto o faltante al usar `O_CREAT`.
  - Olvidar verificar los errores.

## `read`

**Encabezado:** `#include <unistd.h>`

**Descripción:**
Lee hasta `count` bytes de un descriptor de archivo (`fd`) en un buffer (`buf`).

**Detalles:**

  - Retorna el número de bytes realmente leídos.
  - Retorna `0` en EOF (final del archivo).
  - Retorna `-1` en caso de error.

**Ejemplo de Uso Correcto:**

```c
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(void) {
    int fd = open("example.txt", O_RDONLY);
    if (fd == -1) {
        perror("open falló");
        return 1;
    }

    char buffer[100];
    ssize_t bytes_read = read(fd, buffer, sizeof(buffer) - 1);
    if (bytes_read == -1) {
        perror("read falló");
    } else if (bytes_read == 0) {
        printf("Se llegó al EOF.\n");
    } else {
        buffer[bytes_read] = '\0';
        printf("Se leyeron %ld bytes: %s\n", bytes_read, buffer);
    }

    close(fd);
    return 0;
}
```

**Errores Comunes:**

  - No manejar EOF (`0` bytes leídos) por separado.
  - Asumir que el buffer está terminado en nulo automáticamente.

## `close`

**Encabezado:** `#include <unistd.h>`

**Descripción:**
Cierra un descriptor de archivo abierto.

**Detalles:**

  - Libera los recursos asociados con el descriptor de archivo.
  - Importante para prevenir fugas de recursos (quedarse sin descriptores).

**Ejemplo de Uso Correcto:**

```c
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(void) {
    int fd = open("example.txt", O_RDONLY);
    if (fd == -1) {
        perror("open falló");
        return 1;
    }
    
    if (close(fd) == -1)
        perror("close falló");

    return 0;
}
```

**Errores Comunes:**

  - No verificar el valor de retorno, lo que podría pasar por alto errores.
  - Olvidar cerrar los descriptores, lo que lleva a fugas.

-----

## Funciones de Directorio y Sistema de Archivos (`unistd.h`, `sys/stat.h`)

### `getcwd, chdir, stat, lstat, fstat, unlink`

Estas funciones gestionan directorios, manejan rutas de archivos y recuperan información sobre archivos y directorios. También gestionan enlaces del sistema de archivos y el directorio de trabajo actual.

## `getcwd`

**Encabezado:** `#include <unistd.h>`

**Descripción:**
Recupera la ruta de acceso absoluta del directorio de trabajo actual.

**Detalles:**

  - Almacena la ruta absoluta en el buffer proporcionado (`buf`) hasta `size` bytes.
  - Si el buffer es demasiado pequeño o si ocurre un error, retorna `NULL` y establece `errno`.

**Ejemplo de Uso Correcto:**

```c
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

int main(void) {
    char cwd[PATH_MAX];

    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("getcwd falló");
        return 1;
    }

    printf("Directorio de trabajo actual: %s\n", cwd);
    return 0;
}
```

**Errores Comunes:**

  - Proporcionar un tamaño de buffer insuficiente, lo que causa fallos inesperados.
  - Ignorar el valor de retorno y el manejo de errores.

## `chdir`

**Encabezado:** `#include <unistd.h>`

**Descripción:**
Cambia el directorio de trabajo actual del proceso llamante a la ruta especificada.

**Detalles:**

  - Altera el contexto del directorio para operaciones de ruta relativa.
  - Retorna `0` en caso de éxito; `-1` y establece `errno` en caso de fallo.

**Ejemplo de Uso Correcto:**

```c
#include <unistd.h>
#include <stdio.h>

int main(void) {
    if (chdir("/tmp") == -1) {
        perror("chdir falló");
        return 1;
    }

    printf("Directorio cambiado exitosamente a /tmp\n");
    return 0;
}
```

**Errores Comunes:**

  - No manejar el valor de retorno, lo que causa que las operaciones subsiguientes fallen silenciosamente si el cambio de directorio falla.

## `stat`

**Encabezado:** `#include <sys/stat.h>`

**Descripción:**
Recupera información detallada sobre un archivo o enlace simbólico.

**Detalles:**

  - Sigue los enlaces simbólicos y proporciona información sobre el archivo o su destino.
  - La información incluye el tipo de archivo, permisos, tamaño, marcas de tiempo y número de inodo.

**Ejemplo de Uso Correcto:**

```c
#include <sys/stat.h>
#include <stdio.h>

int main(void) {
    struct stat sb;

    if (stat("file.txt", &sb) == -1) {
        perror("stat falló");
        return 1;
    }

    printf("Tamaño del archivo: %lld bytes\n", (long long)sb.st_size);
    printf("Permisos del archivo: %o\n", sb.st_mode & 0777);
    return 0;
}
```

**Errores Comunes:**

  - Interpretar incorrectamente los tipos de archivos al no usar macros como `S_ISREG`, `S_ISDIR` o `S_ISLNK`.
  - Ignorar los valores de retorno, lo que puede llevar a leer datos no válidos.

## `lstat`

**Encabezado:** `#include <sys/stat.h>`

**Descripción:**
Recupera información sobre un archivo o enlace simbólico sin seguir los enlaces simbólicos.

**Detalles:**

  - Útil para obtener detalles específicamente sobre el propio enlace simbólico en lugar de su destino.

**Ejemplo de Uso Correcto:**

```c
#include <sys/stat.h>
#include <stdio.h>

int main(void) {
    struct stat sb;

    if (lstat("link_to_file.txt", &sb) == -1) {
        perror("lstat falló");
        return 1;
    }

    if (S_ISLNK(sb.st_mode))
        printf("Es un enlace simbólico.\n");
    else
        printf("No es un enlace simbólico.\n");

    return 0;
}
```

**Errores Comunes:**

  - Confundir `lstat` con `stat` cuando la intención es obtener información sobre el propio enlace simbólico.
  - Ignorar el valor de retorno, lo que podría llevar a estados de error mal manejados.

## `fstat`

**Encabezado:** `#include <sys/stat.h>`

**Descripción:**
Recupera información sobre un archivo basándose en un descriptor de archivo ya abierto.

**Detalles:**

  - Útil cuando un descriptor de archivo ya está abierto, evitando así búsquedas adicionales por la ruta del archivo.

**Ejemplo de Uso Correcto:**

```c
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(void) {
    int fd = open("file.txt", O_RDONLY);
    if (fd == -1) {
        perror("open falló");
        return 1;
    }

    struct stat sb;
    if (fstat(fd, &sb) == -1) {
        perror("fstat falló");
        close(fd);
        return 1;
    }

    printf("Tamaño del archivo: %lld bytes\n", (long long)sb.st_size);
    close(fd);
    return 0;
}
```

**Errores Comunes:**

  - No verificar el valor de retorno, lo que puede resultar en lecturas de datos no válidos.
  - Interpretar incorrectamente la información del tipo de archivo al no usar las macros adecuadas.

## `unlink`

**Encabezado:** `#include <unistd.h>`

**Descripción:**
Elimina una entrada de directorio (enlace) de un archivo.

**Detalles:**

  - Borra el enlace especificado del sistema de archivos.
  - Si es el último enlace y ningún proceso tiene el archivo abierto, los datos del archivo se eliminan inmediatamente. De lo contrario, la eliminación se pospone hasta que ningún proceso lo esté usando.

**Ejemplo de Uso Correcto:**

```c
#include <unistd.h>
#include <stdio.h>

int main(void) {
    if (unlink("old_file.txt") == -1) {
        perror("unlink falló");
        return 1;
    }

    printf("Archivo desvinculado exitosamente.\n");
    return 0;
}
```

**Errores Comunes:**

  - Esperar la eliminación inmediata de los datos del archivo incluso si otros procesos tienen el archivo abierto.
  - Ignorar errores como problemas de permisos o rutas de archivo faltantes.

## Enlaces Simbólicos (Symlinks)

### ¿Qué son los enlaces simbólicos (symlinks)?

Un enlace simbólico (symlink) es un tipo de archivo especial que contiene una referencia a otro archivo o directorio. Los symlinks proporcionan una forma indirecta de acceder a los recursos de archivos, permitiendo flexibilidad en la estructura y organización del sistema de archivos.

### Creación de un Symlink

Puedes crear un symlink usando el siguiente comando de bash:

```bash
ln -s archivo_original.txt enlace_simbolico_a_original.txt
```

### Verificación de si un Archivo es un Symlink

**Ejemplo de Uso Correcto (usando `lstat`):**

```c
#include <sys/stat.h>
#include <stdio.h>

int main(void) {
    struct stat sb;
    if (lstat("enlace_simbolico_a_original.txt", &sb) == -1) {
        perror("lstat falló");
        return 1;
    }
    if (S_ISLNK(sb.st_mode))
        printf("Es un enlace simbólico.\n");
    else
        printf("No es un enlace simbólico.\n");
    return 0;
}
```