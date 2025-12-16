## **Índice**

  - [Roadmap completo Minishell - Proyecto 42](https://www.google.com/search?q=%23roadmap-completo-minishell---proyecto-42)
      - [Fase 0: Setup y preparación inicial](https://www.google.com/search?q=%23fase-0-setup-y-preparacion-inicial)
          - [0.1 Configuración del entorno](https://www.google.com/search?q=%2301-configuracion-del-entorno)
          - [0.2 Análisis de requisitos](https://www.google.com/search?q=%2302-analisis-de-requisitos)
      - [Fase 1: Fundamentos básicos](https://www.google.com/search?q=%23fase-1-fundamentos-basicos)
          - [1.1 Prompt y Readline](https://www.google.com/search?q=%2311-prompt-y-readline)
          - [1.2 Estructuras de datos básicas](https://www.google.com/search?q=%2312-estructuras-de-datos-basicas)
      - [Fase 2: Parser y análisis léxico](https://www.google.com/search?q=%23fase-2-parser-y-analisis-lexico)
          - [2.1 Tokenización básica](https://www.google.com/search?q=%2321-tokenizacion-basica)
          - [2.2 Análisis sintáctico](https://www.google.com/search?q=%2322-analisis-sintactico)
          - [2.3 Construcción de Command Table](https://www.google.com/search?q=%2323-construccion-de-command-table)
      - [Fase 3: Manejo de comillas y expansión](https://www.google.com/search?q=%23fase-3-manejo-de-comillas-y-expansion)
          - [3.1 Sistema de comillas](https://www.google.com/search?q=%2331-sistema-de-comillas)
          - [3.2 Expansión de variables](https://www.google.com/search?q=%2332-expansion-de-variables)
      - [Fase 4: Ejecución básica de comandos](https://www.google.com/search?q=%23fase-4-ejecucion-basica-de-comandos)
          - [4.1 Identificación de comandos](https://www.google.com/search?q=%2341-identificacion-de-comandos)
          - [4.2 Creación de procesos](https://www.google.com/search?q=%2342-creacion-de-procesos)
      - [Fase 5: Redirecciones](https://www.google.com/search?q=%23fase-5-redirecciones)
          - [5.1 Redirección de entrada](https://www.google.com/search?q=%2351-redireccion-de-entrada)
          - [5.2 Redirección de salida](https://www.google.com/search?q=%2352-redireccion-de-salida)
          - [5.3 Here-Document](https://www.google.com/search?q=%2353-here-document)
      - [Fase 6: Pipes](https://www.google.com/search?q=%23fase-6-pipes)
          - [6.1 Pipes básicos](https://www.google.com/search?q=%2361-pipes-basicos)
          - [6.2 Gestión de descriptores](https://www.google.com/search?q=%2362-gestion-de-descriptores)
          - [6.3 Algoritmo de ejecución con pipes](https://www.google.com/search?q=%2363-algoritmo-de-ejecucion-con-pipes)
      - [Fase 7: Comandos Builtin](https://www.google.com/search?q=%23fase-7-comandos-builtin)
          - [7.1 Implementación de builtins básicos](https://www.google.com/search?q=%2371-implementacion-de-builtins-basicos)
          - [7.2 Builtins de navegación](https://www.google.com/search?q=%2372-builtins-de-navegacion)
          - [7.3 Builtins de entorno](https://www.google.com/search?q=%2373-builtins-de-entorno)
          - [7.4 Builtin de control](https://www.google.com/search?q=%2374-builtin-de-control)
      - [Fase 8: Manejo de señales](https://www.google.com/search?q=%23fase-8-manejo-de-senales)
          - [8.1 Configuración de señales](https://www.google.com/search?q=%2381-configuracion-de-senales)
          - [8.2 Comportamientos específicos](https://www.google.com/search?q=%2382-comportamientos-especificos)
          - [8.3 Contextos de señales](https://www.google.com/search?q=%2383-contextos-de-senales)
      - [Fase 9: Gestión de memoria](https://www.google.com/search?q=%23fase-9-gestion-de-memoria)
      - [Fase 10: Pruebas y validación](https://www.google.com/search?q=%23fase-10-pruebas-y-validacion)
          - [10.1 Checklist de validación](https://www.google.com/search?q=%23101-checklist-de-validacion)
          - [10.2 Pruebas de funcionamiento](https://www.google.com/search?q=%23102-pruebas-de-funcionamiento)
          - [10.3 Pruebas de pipelines](https://www.google.com/search?q=%23103-pruebas-de-pipelines)
          - [10.4 Tests de casos edge](https://www.google.com/search?q=%23104-tests-de-casos-edge)
          - [10.5 Tests de estrés](https://www.google.com/search?q=%23105-tests-de-estres)
      - [Fase 11: Bonus (solo si mandatory es perfecto)](https://www.google.com/search?q=%23fase-11-bonus-solo-si-mandatory-es-perfecto)
          - [11.1 Operadores lógicos](https://www.google.com/search?q=%23111-operadores-logicos)
          - [11.2 Wildcards](https://www.google.com/search?q=%23112-wildcards)
      - [Fase 12: Pulido y entrega](https://www.google.com/search?q=%23fase-12-pulido-y-entrega)
          - [12.1 Revisión de norma](https://www.google.com/search?q=%23121-revision-de-norma)
          - [12.2 Documentación y entrega](https://www.google.com/search?q=%23122-documentacion-y-entrega)
          - [12.3 Validación final](https://www.google.com/search?q=%23123-validacion-final)

-----

# 🛠️ ROADMAP COMPLETO MINISHELL - PROYECTO 42

## 📋 FASE 0: SETUP Y PREPARACIÓN INICIAL

### **0.1 Configuración del Entorno**

  - [cite\_start]Clonar repositorio del proyecto[cite: 1642].
  - Crear estructura de directorios:
      - [cite\_start]`includes/` (headers)[cite: 1644].
      - [cite\_start]`srcs/` (código fuente)[cite: 1645].
      - [cite\_start]`srcs/parser/` (análisis sintáctico)[cite: 1646].
      - [cite\_start]`srcs/executor/` (ejecución)[cite: 1647].
      - [cite\_start]`srcs/builtins/` (comandos internos)[cite: 1648].
      - [cite\_start]`srcs/utils/` (utilidades)[cite: 1649].
      - [cite\_start]`Libft/` (biblioteca personal)[cite: 1650].
  - [cite\_start]Configurar Git con workflow de ramas[cite: 1651].
  - [cite\_start]Copiar `libft` con fuentes y `Makefile`[cite: 1652].
  - [cite\_start]Crear `Makefile` principal con reglas: `NAME`, `all`, `clean`, `fclean`, `re`[cite: 1653].

### **0.2 Análisis de Requisitos**

  - [cite\_start]Estudiar funciones permitidas y prohibidas[cite: 1657].
  - [cite\_start]Revisar gramática de shell en formato Backus-Naur[cite: 1658].
  - [cite\_start]Identificar comportamientos de referencia en bash[cite: 1659].
  - [cite\_start]Definir estructuras de datos principales[cite: 1660].

## 📋 FASE 1: FUNDAMENTOS BÁSICOS

### **1.1 Prompt y Readline**

  - [cite\_start]Implementar prompt básico (`$>` por ejemplo)[cite: 1666].
  - [cite\_start]Integrar función `readline()` para entrada[cite: 1667].
  - [cite\_start]Manejar **EOF** (`Ctrl-D`) para salida limpia[cite: 1668].
  - [cite\_start]Implementar historial con `add_history()`[cite: 1669].
  - [cite\_start]Gestionar memoria de `readline` (permitidas las fugas)[cite: 1670].

### **1.2 Estructuras de Datos Básicas**

  - [cite\_start]Definir estructura **`SimpleCommand`**[cite: 1672]:
      - [cite\_start]Número de argumentos[cite: 1673].
      - [cite\_start]Array de argumentos[cite: 1674].
      - [cite\_start]Métodos de inserción[cite: 1675].
  - Definir estructura **`Command`**:
      - [cite\_start]Array de `SimpleCommands`[cite: 1677].
      - [cite\_start]Archivos de redirección (`input`, `output`, `error`)[cite: 1678].
      - [cite\_start]Flag de background[cite: 1679].
      - [cite\_start]Métodos de manejo[cite: 1683].

## 📋 FASE 2: PARSER Y ANÁLISIS LÉXICO

### **2.1 Tokenización Básica**

  - [cite\_start]Implementar `lexer` para separar tokens básicos[cite: 1686]:
      - [cite\_start]`WORD` (comandos y argumentos)[cite: 1687].
      - [cite\_start]`PIPE` (`|`)[cite: 1688].
      - [cite\_start]`GREAT` (`>`)[cite: 1689].
      - [cite\_start]`LESS` (`<`)[cite: 1690].
      - [cite\_start]`GREATGREAT` (`>>`)[cite: 1691].
      - [cite\_start]`NEWLINE` (`\n`)[cite: 1692].
      - [cite\_start]`AMPERSAND` (`&`)[cite: 1693].

### **2.2 Análisis Sintáctico**

  - [cite\_start]Implementar parser con gramática[cite: 1695]:
      - [cite\_start]`goal`: `command_list`[cite: 1696].
      - [cite\_start]`command list`: `command_list command_line`[cite: 1697].
      - [cite\_start]`command_line`: `pipe_list io_modifier_list background_opt NEWLINE`[cite: 1698].
      - `pipe list`: `pipe_list PIPE cmd_and_args` | [cite\_start]`cmd_and_args`[cite: 1699].
      - [cite\_start]`cmd_and_args`: `WORD arg_list`[cite: 1700].
      - `arg_list`: `arg list WORD` | [cite\_start]`empty`[cite: 1701].
      - `io_modifier_list`: `io_modifier_list io_modifier` | [cite\_start]`empty`[cite: 1702].

### **2.3 Construcción de Command Table**

  - [cite\_start]Llenar estructuras durante parsing[cite: 1705].
  - [cite\_start]Insertar `SimpleCommands` en `Command`[cite: 1706].
  - [cite\_start]Gestionar redirecciones detectadas[cite: 1707].
  - [cite\_start]Manejar recuperación de errores (`error token`)[cite: 1709].

## 📋 FASE 3: MANEJO DE COMILLAS Y EXPANSIÓN

### **3.1 Sistema de Comillas**

  - [cite\_start]Implementar manejo de comillas simples (`'`)[cite: 1712]:
      - [cite\_start]Prevenir interpretación de metacaracteres[cite: 1713].
      - [cite\_start]No expandir variables[cite: 1714].
  - [cite\_start]Implementar manejo de comillas dobles (`"`)[cite: 1715]:
      - Prevenir metacaracteres excepto `$`.
      - [cite\_start]Permitir expansión de variables[cite: 1717].

### **3.2 Expansión de Variables**

  - [cite\_start]Detectar variables de entorno (`$VAR`)[cite: 1626].
  - [cite\_start]Expandir a valores correspondientes[cite: 1626].
  - [cite\_start]Manejar variable especial `$?` (exit status)[cite: 1626].
  - [cite\_start]Gestionar variables no existentes[cite: 1626].

## 📋 FASE 4: EJECUCIÓN BÁSICA DE COMANDOS

### **4.1 Identificación de Comandos**

  - [cite\_start]Distinguir entre `builtins` y binarios externos[cite: 1627].
  - [cite\_start]Buscar ejecutables en `PATH`[cite: 1627].
  - [cite\_start]Manejar rutas absolutas y relativas[cite: 1627].
  - [cite\_start]Gestionar permisos de ejecución[cite: 1627].

### **4.2 Creación de Procesos**

  - [cite\_start]Implementar `fork()` para cada comando[cite: 1627].
  - [cite\_start]Usar `execve()` en procesos hijos[cite: 1627].
  - [cite\_start]Manejar errores de `exec` (comando no encontrado)[cite: 1627].
  - [cite\_start]Implementar `wait`/`waitpid` en proceso padre[cite: 1627].

## 📋 FASE 5: REDIRECCIONES

### **5.1 Redirección de Entrada**

  - [cite\_start]Implementar redirección `<` (input)[cite: 1627].
  - [cite\_start]Abrir archivo con `open()`[cite: 1627].
  - [cite\_start]Redirigir `stdin` con `dup2()`[cite: 1627].
  - [cite\_start]Manejar errores de archivo no encontrado[cite: 1627].

### **5.2 Redirección de Salida**

  - [cite\_start]Implementar redirección `>` (output, truncate)[cite: 1628].
  - [cite\_start]Implementar redirección `>>` (output, append)[cite: 1628].
  - [cite\_start]Crear/truncar archivos según corresponda[cite: 1628].
  - [cite\_start]Redirigir `stdout` con `dup2()`[cite: 1628].

### **5.3 Here-Document**

  - [cite\_start]Implementar redirección `<<` (heredoc)[cite: 1628].
  - [cite\_start]Leer hasta encontrar delimitador[cite: 1628].
  - [cite\_start]No actualizar historial durante lectura[cite: 1628].
  - [cite\_start]Manejar expansión de variables en heredoc[cite: 1628].

## 📋 FASE 6: PIPES

### **6.1 Pipes Básicos**

  - [cite\_start]Crear pipes con `pipe()`[cite: 1628].
  - [cite\_start]Conectar output de comando A con input de comando B[cite: 1629].
  - [cite\_start]Manejar múltiples pipes en pipeline[cite: 1629].

### **6.2 Gestión de Descriptores**

  - [cite\_start]Guardar `stdin`/`stdout` originales con `dup()`[cite: 1629].
  - [cite\_start]Restaurar descriptores al final[cite: 1629].
  - [cite\_start]Cerrar descriptores no utilizados[cite: 1629].
  - [cite\_start]Evitar fugas de file descriptors[cite: 1629].

### **6.3 Algoritmo de Ejecución con Pipes**

  - [cite\_start]Configurar redirecciones antes de `fork`[cite: 1629].
  - [cite\_start]Heredar redirecciones en procesos hijos[cite: 1629].
  - [cite\_start]Esperar solo al último proceso en pipeline[cite: 1629].
  - [cite\_start]Manejar errores en cualquier comando del pipe[cite: 1629].

## 📋 FASE 7: COMANDOS BUILTIN

### **7.1 Implementación de Builtins Básicos**

  - [cite\_start]`echo`: Con opción `-n` (sin newline final)[cite: 1629].
  - [cite\_start]`pwd`: Directorio actual con `getcwd()`[cite: 1629].
  - [cite\_start]`env`: Mostrar variables de entorno[cite: 1629].

### **7.2 Builtins de Navegación**

  - [cite\_start]`cd`: Cambiar directorio con `chdir()`[cite: 1629].
      - [cite\_start]Manejar rutas absolutas y relativas[cite: 1629].
      - [cite\_start]Gestionar variables `HOME` y `OLDPWD`[cite: 1629].
      - [cite\_start]Controlar errores de acceso[cite: 1629].

### **7.3 Builtins de Entorno**

  - [cite\_start]`export`: Modificar variables de entorno[cite: 1630].
      - [cite\_start]Sin argumentos: mostrar todas las variables[cite: 1630].
      - [cite\_start]Con argumentos: establecer variables[cite: 1630].
  - [cite\_start]`unset`: Eliminar variables del entorno[cite: 1630].

### **7.4 Builtin de Control**

  - [cite\_start]`exit`: Terminar shell[cite: 1630].
      - [cite\_start]Manejar código de salida opcional[cite: 1630].
      - [cite\_start]Limpiar recursos antes de salir[cite: 1630].

## 📋 FASE 8: MANEJO DE SEÑALES

### **8.1 Configuración de Señales**

  - [cite\_start]Registrar handlers con `signal()` o `sigaction()`[cite: 1630].
  - [cite\_start]Usar solo una variable global para señales[cite: 1630].
  - [cite\_start]Inicializar máscaras de señales[cite: 1630].

### **8.2 Comportamientos Específicos**

  - [cite\_start]`Ctrl-C` (SIGINT): Nuevo prompt en nueva línea[cite: 1630].
  - [cite\_start]`Ctrl-D` (EOF): Salir del shell limpiamente[cite: 1630].
  - [cite\_start]`Ctrl-\` (SIGQUIT): Ignorar completamente[cite: 1630].

### **8.3 Contextos de Señales**

  - [cite\_start]Comportamiento en modo interactivo[cite: 1630].
  - [cite\_start]Comportamiento durante ejecución de comandos[cite: 1631].
  - [cite\_start]Propagación de señales a procesos hijos[cite: 1631].

## 📋 FASE 9: GESTIÓN DE MEMORIA

## 📋 FASE 10: PRUEBAS Y VALIDACIÓN

### **10.1 Checklist de validación**

### **10.2 Pruebas de funcionamiento**

  - Comandos simples
  - Argumentos múltiples
  - Comillas
  - Redirecciones
  - Variables de entorno

### **10.3 Pruebas de Pipelines**

  - Pipes de 2, 3 o más comandos
  - Pipes con redirecciones
  - Pipes con builtins

### **10.4 Tests de Casos Edge**

  - Comillas anidadas
  - Variables inexistentes
  - Comandos vacíos
  - Espacios y tabs excesivos
  - Señales durante ejecución

### **10.5 Tests de Estrés**

  - Pipelines muy largas
  - Múltiples redirecciones
  - Comandos con muchos argumentos
  - Recursión de shells (`./minishell` dentro de `minishell`)

## 📋 FASE 11: BONUS (SOLO SI MANDATORY ES PERFECTO)

### **11.1 Operadores Lógicos**

  - Implementar `&&` (AND lógico)
  - Implementar `||` (OR lógico)
  - Manejar paréntesis para prioridades
  - Evaluación perezosa (`short-circuit`)

### **11.2 Wildcards**

  - Implementar expansión `*` para directorio actual
  - Convertir wildcards a expresiones regulares
  - Ordenar entradas encontradas
  - Manejar archivos ocultos (que empiecen por `.`)

## 📋 FASE 12: PULIDO Y ENTREGA

### **12.1 Revisión de Norma**

  - Verificar cumplimiento de norma de 42
  - Revisar nombres de funciones y variables
  - Controlar longitud de líneas y funciones
  - Validar estructura de archivos

### **12.2 Documentación y Entrega**

  - Completar `Makefile` con todas las reglas
  - Verificar nombres de archivos
  - Limpiar código de `debug`
  - Preparar defensa técnica

### **12.3 Validación Final**

  - Ejecutar batería completa de tests
  - Verificar comportamiento idéntico a bash
  - Confirmar ausencia de `memory leaks`
  - Probar en diferentes entornos