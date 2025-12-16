# Resumen de Cambios en la Rama

## 1. Comentarios guía en `main()`

En el archivo `minishell.c`, dentro de la función `main()`, se han añadido comentarios que sirven como guía para el futuro desarrollo del manejo de tokens tras el parseo del input del usuario. Estos comentarios anticipan cómo se podrían gestionar los distintos tipos de redirecciones y comandos, aunque aún no están implementados. La idea es dejar claro el flujo general:

- Si el input contiene redirecciones (`input_file`, `output_file`, `here_doc`, `append`), se llamarán a funciones específicas para obtener los file descriptors correspondientes.
- Si hay comandos, se ejecutarán.
- Si hay pipes, se gestionarán con una función aparte.

Estos comentarios no afectan la ejecución actual, pero orientan el desarrollo futuro.

---

## 2. Nuevo archivo: `input_output.c`

Se ha añadido el archivo `input_output.c`, que implementa funciones para abrir archivos y obtener file descriptors según el tipo de redirección que se desee realizar en el shell.

### Funciones implementadas

- **`get_inputfile_fd(char *infile)`**  
  Abre un archivo en modo solo lectura (`O_RDONLY`).  
  Devuelve el file descriptor o `-1` si hay error.

- **`get_outputfile_fd(char *outfile)`**  
  Abre (o crea) un archivo en modo escritura, truncando su contenido (`O_CREAT | O_WRONLY | O_TRUNC`).  
  Devuelve el file descriptor o `-1` si hay error.

- **`get_append_fd(char *outfile)`**  
  Abre (o crea) un archivo en modo escritura, pero añade al final (`O_CREAT | O_WRONLY | O_APPEND`).  
  Devuelve el file descriptor o `-1` si hay error.

---

### Detalle especial: `get_heredoc_fd(char *limiter)`

Esta función implementa la lógica para el manejo de la redirección tipo *heredoc* (`<<`). Su funcionamiento es el siguiente:

1. **Crea un pipe** para comunicar procesos.
2. **Hace un fork** para crear un proceso hijo:
   - **Hijo:**  
     - Restaura el comportamiento por defecto de `SIGINT` (Ctrl+C).
     - Lee líneas del usuario hasta que se introduce el *limiter*.
     - Escribe cada línea en el pipe.
     - Si se recibe EOF o Ctrl+D, termina.
   - **Padre:**  
     - Ignora `SIGINT` mientras el hijo está activo.
     - Espera a que el hijo termine.
     - Si el hijo fue interrumpido por `SIGINT`, cierra el pipe y devuelve error.
     - Si todo va bien, devuelve el file descriptor de lectura del pipe, que contiene el contenido del heredoc.

**Ventaja:**  
Si el usuario pulsa Ctrl+C durante el heredoc, solo se interrumpe el heredoc y no el minishell completo, imitando el comportamiento de shells reales.

---

## Resumen

- Se han añadido comentarios en `main()` para guiar el futuro manejo de tokens y redirecciones.
- Se ha creado `input_output.c` con funciones para abrir archivos/redirecciones.
- `get_heredoc_fd` destaca por su manejo correcto de señales y procesos para implementar heredoc de forma robusta.