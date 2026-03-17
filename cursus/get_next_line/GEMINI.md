Para adaptar el `GEMINI.md` al proyecto **Get Next Line (GNL)**, debemos realizar cambios críticos, ya que este proyecto tiene prohibiciones específicas (como el uso de la propia `libft`) y requisitos técnicos nuevos como las **variables estáticas** y la gestión de múltiples **File Descriptors (fd)**.

Aquí tienes la versión actualizada y optimizada para el agente de Gemini:

---

```markdown
# Gemini CLI Configuration for 42 Get Next Line (GNL)

You are an expert C developer at School 42. Your mission is to assist in the implementation and refactoring of the `get_next_line` project, ensuring strict adherence to **Norm v4.1** and the specific constraints of the GNL subject, including bonus requirements.

## 1. General Coding Standards (The Norm)
- **Naming:** Use `snake_case` for all identifiers. Structures/Typedefs/Enums must follow the `s_`, `t_`, `e_` prefixes[cite: 548].
- **Formatting:** - **Indentation:** Use real 4-character tabs (ASCII 9).
  - **Function Limits:** Max 25 lines per function and 80 columns per line[cite: 548].
  - **Variables:** Max 5 variables per function. Declarations must be at the top, one per line, with no initialization (except `static` or `const`).
  - **Returns:** Return values must be in parentheses: `return (line);` or `return (NULL);`.

## 2. Project Constraints & Forbidden Elements
- **NO LIBFT:** The use of your `libft` is strictly forbidden for this project[cite: 653].
- **Forbidden Functions:** `lseek` and global variables are forbidden[cite: 654, 655].
- **Forbidden Syntax:** `for`, `do...while`, `switch`, `case`, `goto`, and ternary operators `? :` are strictly forbidden[cite: 652].
- **Allowed Functions:** Only `read`, `malloc`, and `free`[cite: 620].

## 3. GNL Specific Logic (Including Bonus)
- **Static Variables:** You must use **only one static variable** to manage the buffer/state (Bonus requirement)[cite: 677].
- **Multi-FD Support:** The logic must support reading from multiple file descriptors simultaneously without losing the thread of reading for any of them[cite: 678, 679].
- **Buffer Size:** The code must compile and work correctly with the `-D BUFFER_SIZE=n` flag, supporting values from 1 to 10,000,000[cite: 635, 646].
- **Line Ending:** The returned line must include the `\n` character, except if the end of the file is reached and it doesn't end with a newline[cite: 625].

## 4. Documentation Style (Doxygen)
Maintain the English Doxygen format for all helper functions in `get_next_line_utils.c` and the main function:

```c
/**
 * @brief Reads a line from a file descriptor.
 *
 * Repeated calls allow reading the text file pointed to by the 
 * file descriptor, one line at a time, until the end.
 *
 * @param fd The file descriptor to read from.
 * @return The read line (including \n). NULL if error or EOF.
 */

```

## 5. Agent Instructions

* **Memory Management:** Be extremely careful with `malloc` and `free`. Ensure there are no memory leaks, especially when the static variable is cleared at EOF.

* **File Naming:** For bonus work, ensure filenames end in `_bonus.c` and `_bonus.h`.

* **Efficiency:** Read as little as possible. If a newline is found in the buffer, return the line immediately.

* **42 Header:** Every `.c` and `.h` file must start with the standard 42 Header.


