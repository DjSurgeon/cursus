# AGENTS.md - Libft 42 Project Context

## 1. Build and Test Commands
- **Build Library:** `make`
- **Clean Objects:** `make clean`
- **Full Clean:** `make fclean`
- **Rebuild:** `make re`
- **Build Bonus:** `make bonus`
- **Run Tests:** `make test`
- **Individual Test:** `./test_runner <function_name>` (e.g., `./test_runner ft_atoi`)
- **Norm Check:** `norminette src/*.c libft.h`

## 2. Code Style Guidelines (Norm v4.1)
All code must strictly adhere to the 42 School Norm:
- **No forbidden loops:** `for`, `do...while` are strictly forbidden. Use `while`.
- **No forbidden structures:** `switch`, `case`, `goto` are forbidden.
- **No ternaries:** The `? :` operator is forbidden.
- **Indentation:** Use real tabs (4 characters wide), not spaces.
- **Function limits:** Max 25 lines per function.
- **Variable limits:** Max 5 variables per function, declared at the start.
- **Columns:** Max 80 characters per line.

## 3. Naming Conventions
- **Files/Functions/Variables:** `snake_case`.
- **Structures:** Prefix with `s_` (e.g., `t_list` using `struct s_list`).
- **Typedefs:** Prefix with `t_`.
- **Globals:** Prefix with `g_`.

## 4. Documentation (Doxygen Style)
Every function must have a header outside the body:
/**
 * @brief Short description.
 * @param p1 Description.
 * @return Description of return.
 */

## 5. Refactoring Policy
- **DO NOT** rewrite entire files if not requested.
- **DO** use incremental edits.
- **DO** protect all `malloc` calls.
- **DO** ensure zero memory leaks (Valgrind ready).