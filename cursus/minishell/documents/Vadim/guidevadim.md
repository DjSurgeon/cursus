## **Índice**

  - [Puntos clave para desarrollar el proyecto](https://www.google.com/search?q=%23puntos-clave-para-desarrollar-el-proyecto)
      - [1. Inicialización del programa](https://www.google.com/search?q=%231-inicializacion-del-programa)
      - [2. Loop principal tipo REPL](https://www.google.com/search?q=%232-loop-principal-tipo-repl)
      - [3. Lectura y parsing de input](https://www.google.com/search?q=%233-lectura-y-parsing-de-input)
      - [4. Ejecución de comandos](https://www.google.com/search?q=%234-ejecucion-de-comandos)
      - [5. Builtins mínimos](https://www.google.com/search?q=%235-builtins-minimos)
      - [6. Redirecciones](https://www.google.com/search?q=%236-redirecciones)
      - [7. Gestión de señales](https://www.google.com/search?q=%237-gestion-de-senales)
      - [8. Variables de entorno](https://www.google.com/search?q=%238-variables-de-entorno)
      - [9. Manejo de errores](https://www.google.com/search?q=%239-manejo-de-errores)
  - [Posibles enfoques (comparación rápida)](https://www.google.com/search?q=%23posibles-enfoques-comparacion-rapida)
  - [Sugerencia de estructura mínima de archivos](https://www.google.com/search?q=%23sugerencia-de-estructura-minima-de-archivos)
  - [Recomendaciones finales](https://www.google.com/search?q=%23recomendaciones-finales)

-----

## **Puntos clave para desarrollar el proyecto** (ordenados de forma lógica)

### **1. Inicialización del programa**

  - Leer las variables de entorno (**`envp`**) y crear una copia modificable.
  - Configurar estructuras globales si es necesario.

### **2. Loop principal tipo REPL** (Read - Eval - Print - Loop)

Esta es una forma muy intuitiva de desarrollar el proyecto:

```c
while (1)
{
    // READ
    Mostrar prompt($> por ejemplo) y leer la línea de entrada (usando readline).
    
    // PARSE
    Parsear la línea: dividir en comandos, argumentos, redirecciones, etc.
    
    // EXECUTE
    Ejecutar el comando (con fork/execve o builtins(aplicados dentro del proceso padre)).
    
    // PRINT (implícito si el comando genera salida)
    
    // LOOP se repite
}
```

### **3. Lectura y parsing de input**

  - Usar **`readline()`** para entrada interactiva.
  - Implementar tokenización básica:
      - Separar comandos y argumentos.
      - Detectar `|`, `>`, `>>`, `<`, `<<`.
      - Manejo de comillas simples y dobles.
  - (No es necesario implementar un parser tipo AST (árbol de sintaxis abstracta); con estructuras simples se puede resolver)

### **4. Ejecución de comandos** (este punto debería poder fusilarlo de mi pipex extendido, pero hay que adaptarlo mucho)

  - Comandos simples: `ls`, `echo`, `cat`, etc.
      - Buscar en el `PATH`.
      - Usar **`fork()`** y **`execve()`**.
  - Comandos con argumentos.
  - Comandos con redirecciones (`>`, `>>`, `<`).
  - Comandos encadenados con `pipes` (`|`).
      - Implementar **`pipe()`** y **`dup2()`** en los procesos hijos.
      - Cierre adecuado de descriptores.

### **5. Builtins mínimos**

Implementar directamente en el proceso padre (sin **`fork()`**):

  - **`cd`**
  - **`echo`**
  - **`pwd`**
  - **`exit`**
  - **`export`**
  - **`unset`**
  - **`env`**

### **6. Redirecciones** (la lógica de aquí se saca también del pipex)

  - `>` → redirección de salida (crear archivo/truncar).
  - `>>` → redirección de salida (`append`).
  - `<` → redirección de entrada (leer archivo).
  - `<<` (heredoc) → entrada desde línea hasta un delimitador.

### **7. Gestión de señales**

  - `Ctrl+C` debe cancelar el comando en curso pero no salir del shell.
  - `Ctrl+\` ignorado.
  - Manejo adecuado de señales en procesos hijos.

### **8. Variables de entorno**

  - Exportar, modificar, eliminar.
  - Manejar `export` y `unset`.
  - Usar `environ` o estructura propia.

### **9. Manejo de errores**

  - Mensajes de error estándar (ej. `comando no encontrado`).
  - Códigos de salida correctos.
  - Verificar `malloc`, `fork`, `open`, etc.

-----

## **🧭 Posibles enfoques** (comparación rápida)

| Enfoque | Ventajas | Desventajas |
| :--- | :--- | :--- |
| **REPL Loop** | Modular, fácil de testear cada parte. Natural para shell. | Hay que cuidar manejo de memoria entre ciclos. |
| **Parser centralizado (AST)** | Escalable si planeas bonus o expansión. | Más complejo y costoso de mantener. |
| **Ejecución tipo pipeline lineal** | Simplicidad, encadena comandos como una lista. | Menos flexible con estructuras complejas. |

Mi recomendación: empieza con **REPL** + estructuras lineales simples (listas de comandos, structs para redirecciones, etc.).

-----

## **🛠 Sugerencia de estructura mínima de archivos**

```bash
minishell/
│
├── main.c               // Loop REPL
├── parser.c/.h          // Parsing y tokenización
├── executor.c/.h        // Ejecución de comandos
├── builtins.c/.h        // Funciones como cd, echo, etc.
├── env.c/.h             // Manejo de variables de entorno
├── signals.c/.h         // Gestión de señales
├── utils.c/.h           // Funciones auxiliares
└── Makefile
```

-----

## **🚀 Recomendaciones finales**

  - Ve integrando partes una a una: primero **REPL** básico con `echo`, luego `parsing`, luego `ejecución`.
  - Escribe pequeños test interactivos (ej. `ls -l | grep .c > files.txt`).
  - Haz un buen control de errores y memoria: **`valgrind`** desde el principio.
  - No intentes hacer todo de golpe, cada *feature* puede ser una etapa.