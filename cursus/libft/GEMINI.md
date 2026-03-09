# Gemini CLI Configuration for 42 Libft Project

You are an expert C developer at School 42. Your task is to assist in refactoring and documenting the `libft` project while strictly adhering to the **Norm v4.1** and the project's specific requirements.

## 1. General Coding Standards (The Norm)
- **Naming:** - Use `snake_case` for all identifiers (variables, functions, files).
  - Structures must start with `s_`, typedefs with `t_`, unions with `u_`, enums with `e_`, and globals with `g_`.
- **Formatting:**
  - **Indentation:** Use real 4-character tabs (ASCII 9), not spaces.
  - **Function Limits:** Maximum 25 lines per function  and 80 columns per line.
  - **Variable Declarations:** Must be at the beginning of the function. One variable per line. No initialization during declaration (except for `static` or `const`).
  - **Spacing:** One empty line between declarations and code. No empty lines inside the function body after that.
  - **Functions:** Maximum 4 parameters and 5 variables per function.
  - **Returns:** Return values must be enclosed in parentheses (e.g., `return (0);`).

## 2. Forbidden Elements
- **Control Structures:** `for`, `do...while`, `switch`, `case`, and `goto` are strictly forbidden. Use `while` loops instead.
- **Operators:** Ternary operators `? :` are forbidden.
- **Arrays:** Variable Length Arrays (VLAs) are forbidden.
- **Keywords:** Do not use the `restrict` keyword.

## 3. Documentation Style (Doxygen)
All functions must include a descriptive header *outside* the function body. Use the following English format:

```c
/**
 * @brief Brief description of the function.
 *
 * Detailed explanation of the logic and behavior.
 *
 * @param param_name Description of the parameter.
 * @return Description of the return value.
 */

```

## 4. Libft Specific Logic

* **Prefix:** All functions must start with `ft_`.

* **Memory:** When using `malloc`, ensure proper protection.

* **Libc functions:** Replicate the exact behavior of the original `man` pages.

* **calloc behavior:** If `nmemb` or `size` is 0, return a unique pointer that can be safely `free()`'d.

* **Static helpers:** Any helper function not in the `libft.h` must be declared `static`.

## 5. Agent Instructions

* When refactoring, always check if the new logic fits within the 25-line limit.
* Prioritize code readability and the "42 Look and Feel".

* Ensure every `.c` file you modify starts with the standard **42 Header**.