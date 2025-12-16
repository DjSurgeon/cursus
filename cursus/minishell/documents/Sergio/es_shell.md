# Escribiendo tu Propio Shell

*"Realmente entiendes algo cuando lo programas."*  
— GRR

---

## Índice
- [Introducción](#introducción)
- [Programas Shell](#programas-shell)
- [Partes de un Programa Shell](#partes-de-un-programa-shell)
  - [El Parser](#el-parser)
  - [El Ejecutor](#el-ejecutor)
  - [Subsistemas del Shell](#subsistemas-del-shell)
- [Uso de Lex y Yacc para Implementar el Parser](#uso-de-lex-y-yacc-para-implementar-el-parser)
- [Gramática del Shell](#gramática-del-shell)
- [La Tabla de Comandos](#la-tabla-de-comandos)
- [Implementación del Analizador Léxico](#implementación-del-analizador-léxico)
- [Añadiendo Nuevos Tokens](#añadiendo-nuevos-tokens)
- [Creación de Procesos en tu Shell](#creación-de-procesos-en-tu-shell)
- [Redirecciones y Pipes](#redirecciones-y-pipes)
- [Funciones Internas (*Built-ins*)](#funciones-internas-built-ins)
- [Implementación de Wildcards](#implementación-de-wildcards)
  - [Ordenación de Entradas de Directorio](#ordenación-de-entradas-de-directorio)
  - [Wildcards y Archivos Ocultos](#wildcards-y-archivos-ocultos)
  - [Wildcards en Subdirectorios](#wildcards-en-subdirectorios)

---

## Introducción
En el capítulo anterior se trató cómo usar un programa *shell* mediante comandos UNIX.  
El *shell* es un programa que interactúa con el usuario a través de una terminal o que toma la entrada de un archivo y ejecuta una secuencia de comandos que son pasados al sistema operativo.  

En este capítulo aprenderás a escribir tu propio programa *shell*.

---

## Programas Shell
Un programa *shell* es una aplicación que permite interactuar con el ordenador.  
Con él, el usuario puede ejecutar programas y redirigir entradas/salidas hacia/desde archivos.  

Además, los shells ofrecen construcciones de programación como `if`, `for`, `while`, funciones, variables, etc. También incluyen utilidades como edición de línea, historial, autocompletado de archivos, *wildcards*, expansión de variables de entorno, etc.

**Shells más comunes en UNIX:**
- `sh`: el shell original.
- `csh`: el *C Shell*, una versión mejorada.
- `tcsh`: variante de *csh* con edición de línea.
- `ksh`: *Korn Shell*, base de shells avanzados.
- `bash`: el shell de GNU, actualmente el más utilizado.

También existen shells gráficos como el Escritorio de Windows, Finder en MacOS, o GNOME/KDE en Linux.  
Estos simplifican el uso para la mayoría de usuarios, pero no sustituyen al *command-line shell* para tareas complejas.

---

## Partes de un Programa Shell
La implementación de un shell suele dividirse en tres componentes:

### El Parser
Lee la línea de comandos (ej: `ls -al`) y la traduce a una estructura de datos llamada **Tabla de Comandos**, donde se almacenan los comandos que se ejecutarán.

### El Ejecutor
Toma la tabla de comandos y crea un proceso por cada **comando simple**.  
También establece tuberías entre procesos y aplica redirecciones de entrada, salida o error según corresponda.

### Subsistemas del Shell
- **Variables de entorno**: soportar `${VAR}`, asignación e impresión.  
- **Wildcards**: expansión de patrones como `a*a`.  
- **Subshells**: ejecutar comandos entre backticks `` `cmd` `` y usar su salida como entrada.

Implementar tu propio shell ayuda a comprender cómo interactúan los intérpretes de comandos y el sistema operativo.

---

## Uso de Lex y Yacc para Implementar el Parser
Para construir el parser se usan **Lex** (analizador léxico) y **Yacc** (parser).  
Estos dividen el problema en:

- **Lexer**: transforma caracteres en *tokens*.  
- **Parser**: procesa los tokens según una gramática y construye la tabla de comandos.

---

## Gramática del Shell
Ejemplo en **forma de Backus-Naur (BNF):**
```
cmd [arg]* [ | cmd [arg]* ]*
       [ [> filename] [< filename] [>& filename] [>> filename] [>>& filename] ]* [&]
```

Acepta comandos como:
```bash
ls -al
ls -al > out
ls -al | sort >& out
awk -f x.awk | sort -u < infile > outfile &
```

---

## La Tabla de Comandos
Se representa mediante estructuras:
```cpp
struct SimpleCommand {
    int _numberOfArguments;
    char **_arguments;
    void insertArgument(char *argument);
};

struct Command {
    int _numberOfSimpleCommands;
    SimpleCommand **_simpleCommands;
    char *_outFile;
    char *_inputFile;
    char *_errFile;
    int _background;
    void execute();
};
```

Ejemplo:
```
ls -al | grep me > file1
```

Tabla de comandos generada:
```
0: ls -al
1: grep me
Salida -> file1
```

---

## Implementación del Analizador Léxico
Archivo `shell.l` con expresiones regulares para definir tokens (`WORD`, `PIPE`, `GREAT`, etc.).  
Se procesa con `lex` → genera `lex.yy.c` (scanner).

---

## Añadiendo Nuevos Tokens
Nuevos símbolos (`>>`, `|`, `&`, etc.) deben agregarse tanto en `shell.l` como en `shell.y`.

---

## Creación de Procesos en tu Shell
Cada comando simple se ejecuta en un proceso separado con `fork()` y `execvp()`.  
El padre espera al último comando si no está en *background* (`&`).

---

## Redirecciones y Pipes
El padre prepara las redirecciones antes de `fork()`, de modo que los hijos hereden la configuración.  
Ejemplos:
- `cmd < infile`
- `cmd > outfile`
- `cmd1 | cmd2 | cmd3`

---

## Funciones Internas (*Built-ins*)
Se ejecutan en el proceso padre (ej: `cd`, `setenv`, `unsetenv`).  
Otras (`printenv`) pueden correr en procesos hijos.

---

## Implementación de Wildcards
Los comodines (`*`, `?`) se traducen a expresiones regulares y se expanden recorriendo directorios.  

### Ordenación de Entradas de Directorio
Shells como `bash` ordenan las coincidencias. Ejemplo: `echo *` devuelve archivos ordenados alfabéticamente.

### Wildcards y Archivos Ocultos
Archivos que empiezan con `.` no deben coincidir salvo que el patrón también comience con `.`.

### Wildcards en Subdirectorios
Soportar patrones como:
```bash
echo /p*/*a/b*/aa*
```

---
