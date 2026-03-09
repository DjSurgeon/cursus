*Este proyecto ha sido creado como parte del currículo de 42 por serjimen*

# 📚 Libft - Your First C Library

## 📝 Description
This project consists of coding a C library that contains a series of general-purpose functions that can be used in future 42 projects. The goal is to understand how standard functions work by re-implementing them from scratch.

The library is strictly written following the **Norm v4.1** and focuses on three main areas:
1.  **Libc functions:** Re-implementing standard functions like `strlen`, `memcpy`, etc.
2.  **Additional functions:** Utility functions not present in libc, such as `ft_split`, `ft_itoa`, or `ft_strjoin`.
3.  **Linked Lists:** A set of functions to manipulate data structures using nodes.

## 🛠️ Technical Skills & Learning
- **Memory Management:** Extensive use of `malloc` and `free`, ensuring zero leaks (checked with Valgrind/Leaks).
- **Pointers & Logic:** Manipulation of strings and complex data structures through pointers.
- **Constraint-Driven Development:** Adhering to the 42 Norm (max 25 lines per function, no forbidden control structures like `for` or `switch`).
- **Static Analysis:** Using the `norminette` to verify code quality and style.

## 💻 Instructions
### Compilation
The project includes a `Makefile` that compiles the library into `libft.a`.
- `make`: Compiles the library.
- `make clean`: Removes object files.
- `make fclean`: Removes object files and the library.
- `make re`: Recompiles the entire project.
- `make bonus`: Compiles the linked list functions.

### Usage
To use this library in your own C projects, include the header and link the library:
```c
#include "libft.h"
```

## 📋 Function Reference

| Function | Description | Return Value |
| :--- | :--- | :--- |
| `ft_atoi` | Converts a string to an integer (ASCII to Int). | The converted integer value. |
| `ft_bzero` | Erases data in the n bytes of the memory starting at s. | None |
| `ft_calloc` | Allocates memory for an array and sets it to zero. | Pointer to allocated memory, or NULL if fails. |
| `ft_countchar` | Writes a character to stdout and counts it. | Number of characters written (1 if successful). |
| `ft_isalnum` | Checks for an alphanumeric character. | 1 if alphanumeric, 0 otherwise. |
| `ft_isalpha` | Checks for an alphabetic character. | 1 if alphabetic, 0 otherwise. |
| `ft_isascii` | Checks if character fits into the ASCII set. | 1 if ASCII, 0 otherwise. |
| `ft_isdigit` | Checks for a digit (0 through 9). | 1 if digit, 0 otherwise. |
| `ft_isprint` | Checks for any printable character including space. | 1 if printable, 0 otherwise. |
| `ft_isspace` | Checks for white-space characters. | 1 if whitespace, 0 otherwise. |
| `ft_itoa` | Converts integer to a string. | String representation of the integer, or NULL. |
| `ft_lstadd_back` | Adds node 'new' at the end of the list. | None |
| `ft_lstadd_front` | Adds node 'new' at the beginning of the list. | None |
| `ft_lstclear` | Deletes and frees a list and its successors. | None |
| `ft_lstdelone` | Frees a single node's content and the node itself. | None |
| `ft_lstiter` | Applies function 'f' to each node's content. | None |
| `ft_lstlast` | Returns the last node of the list. | The last node of the list. |
| `ft_lstmap` | Creates a new list by applying 'f' to each node. | The new list, or NULL if fails. |
| `ft_lstnew` | Allocates and returns a new node. | The new node. |
| `ft_lstsize` | Counts the number of nodes in a list. | The length of the list. |
| `ft_memchr` | Scans memory for the first instance of c. | Pointer to matching byte, or NULL. |
| `ft_memcmp` | Compares the first n bytes of two memory areas. | <0, 0, or >0 depending on comparison. |
| `ft_memcpy` | Copies n bytes from src to dest (non-overlapping). | A pointer to dest. |
| `ft_memmove` | Copies n bytes from src to dest (overlap safe). | A pointer to dest. |
| `ft_memset` | Fills memory with a constant byte c. | A pointer to the memory area s. |
| `ft_putchar_fd` | Outputs character 'c' to a file descriptor. | None |
| `ft_putendl_fd` | Outputs string 's' to a fd followed by a newline. | None |
| `ft_putnbr_fd` | Outputs integer 'n' to a file descriptor. | None |
| `ft_putstr_fd` | Outputs string 's' to a file descriptor. | None |
| `ft_split` | Splits string 's' into an array using delimiter 'c'. | Array of new strings, or NULL. |
| `ft_strchr` | Locates the first occurrence of c in s. | Pointer to first occurrence, or NULL. |
| `ft_strdup` | Duplicates a string s. | Pointer to duplicated string, or NULL. |
| `ft_striteri` | Applies 'f' to each char of s (with index). | None |
| `ft_strjoin` | Concatenates 's1' and 's2' into a new string. | The new string, or NULL. |
| `ft_strlcat` | Appends src to dst with buffer size control. | Total length of the string attempted to create. |
| `ft_strlcpy` | Copies src to dst with buffer size control. | Total length of the string attempted to create. |
| `ft_strlen` | Calculates the length of a string. | Number of characters (0 if s is NULL). |
| `ft_strmapi` | Creates a new string by applying 'f' to each char. | The new string, or NULL. |
| `ft_strncmp` | Compares up to n characters of two strings. | <0, 0, or >0 depending on comparison. |
| `ft_strnstr` | Locates 'little' in 'big' within 'len' characters. | Pointer to occurrence, big, or NULL. |
| `ft_strrchr` | Locates the last occurrence of c in s. | Pointer to last occurrence, or NULL. |
| `ft_strtrim` | Trims specified characters from start and end. | The trimmed string, or NULL. |
| `ft_substr` | Creates a substring from 's'. | The substring, or NULL. |
| `ft_tolower` | Converts uppercase letter to lowercase. | Converted character or original. |
| `ft_toupper` | Converts lowercase letter to uppercase. | Converted character or original. |