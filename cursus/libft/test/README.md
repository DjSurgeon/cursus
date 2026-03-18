# Libft Test Suite

This directory contains a custom test suite for verifying the functionality of the `libft` library. The tests are designed to ensure compliance with standard behaviors and handle edge cases.

## Advanced Testing Capabilities

Our test suite now integrates advanced analysis tools to ensure maximum reliability:

1. **Deep Static Analysis (`-fanalyzer`)**: Every test script first performs a deep static scan of the source file. This detects complex logical errors, NULL dereferences, and potential memory hazards before execution.
2. **Memory Safety with Valgrind**: All test runners are executed under Valgrind's supervision. This guarantees that:
   - There are no memory leaks.
   - All memory accesses are valid (no out-of-bounds reads/writes).
   - Only initialized memory is read.

## Directory Structure

- **`scripts/`**: Contains Bash scripts that automate the compilation and execution of tests.
  - `test_libft.sh`: The main entry point that runs all available tests.
  - `test_ft_atoi.sh`: Individual test script for `ft_atoi`.
  - `test_ft_bzero.sh`: Individual test script for `ft_bzero`.
  - `test_ft_calloc.sh`: Individual test script for `ft_calloc`.
  - `test_ft_countchar.sh`: Individual test script for `ft_countchar`.
  - `test_ft_isalnum.sh`: Individual test script for `ft_isalnum`.
  - `test_ft_isalpha.sh`: Individual test script for `ft_isalpha`.
  - `test_ft_isascii.sh`: Individual test script for `ft_isascii`.
  - `test_ft_isdigit.sh`: Individual test script for `ft_isdigit`.
  - `test_ft_isprint.sh`: Individual test script for `ft_isprint`.
  - `test_ft_isspace.sh`: Individual test script for `ft_isspace`.
  - `test_ft_itoa.sh`: Individual test script for `ft_itoa`.
  - `test_ft_lstadd_back.sh`: Individual test script for `ft_lstadd_back`.
  - `test_ft_lstadd_front.sh`: Individual test script for `ft_lstadd_front`.
  - `test_ft_lstclear.sh`: Individual test script for `ft_lstclear`.
  - `test_ft_lstdelone.sh`: Individual test script for `ft_lstdelone`.
  - `test_ft_lstiter.sh`: Individual test script for `ft_lstiter`.
  - `test_ft_memchr.sh`: Individual test script for `ft_memchr`.
  - `test_ft_memcmp.sh`: Individual test script for `ft_memcmp`.
  - `test_ft_memcpy.sh`: Individual test script for `ft_memcpy`.
  - `test_ft_strjoin.sh`: Individual test script for `ft_strjoin`.
- **`src/`**: Contains C source files (test runners) that implement the actual comparison logic.
  - `test_atoi_runner.c`: Compares `ft_atoi` results against the standard `atoi`.
  - `test_bzero_runner.c`: Compares `ft_bzero` results against the standard `bzero`.
  - `test_calloc_runner.c`: Verifies `ft_calloc` memory allocation and zero-initialization.
  - `test_countchar_runner.c`: Verifies `ft_countchar` character output and return value.
  - `test_isalnum_runner.c`: Compares `ft_isalnum` results against the standard `isalnum`.
  - `test_isalpha_runner.c`: Compares `ft_isalpha` results against the standard `isalpha`.
  - `test_isascii_runner.c`: Compares `ft_isascii` results against the standard `isascii`.
  - `test_isdigit_runner.c`: Compares `ft_isdigit` results against the standard `isdigit`.
  - `test_isprint_runner.c`: Compares `ft_isprint` results against the standard `isprint`.
  - `test_isspace_runner.c`: Compares `ft_isspace` results against the standard `isspace`.
  - `test_itoa_runner.c`: Verifies `ft_itoa` integer to string conversion.
  - `test_lstadd_back_runner.c`: Verifies `ft_lstadd_back` linked list addition.
  - `test_lstadd_front_runner.c`: Verifies `ft_lstadd_front` linked list addition.
  - `test_lstclear_runner.c`: Verifies `ft_lstclear` linked list clearing.
  - `test_lstdelone_runner.c`: Verifies `ft_lstdelone` linked list node deletion.
  - `test_lstiter_runner.c`: Verifies `ft_lstiter` linked list iteration and function application.
  - `test_memchr_runner.c`: Compares `ft_memchr` results against the standard `memchr`.
  - `test_memcmp_runner.c`: Compares `ft_memcmp` results against the standard `memcmp`.
  - `test_memcpy_runner.c`: Compares `ft_memcpy` results against the standard `memcpy`.
  - `test_strjoin_runner.c`: Verifies `ft_strjoin` string concatenation and memory allocation.

## How to Run the Tests

### Run All Tests
To execute the entire test suite, run the following command from the project root:
```bash
bash test/scripts/test_libft.sh
```

### Run Individual Tests
You can also run tests for a specific function by executing its corresponding script:
```bash
cd test/scripts
./test_ft_atoi.sh
./test_ft_bzero.sh
./test_ft_calloc.sh
./test_ft_countchar.sh
./test_ft_isalnum.sh
./test_ft_isalpha.sh
./test_ft_isascii.sh
./test_ft_isdigit.sh
./test_ft_isprint.sh
./test_ft_isspace.sh
./test_ft_itoa.sh
./test_ft_lstadd_back.sh
./test_ft_lstadd_front.sh
./test_ft_lstclear.sh
./test_ft_lstdelone.sh
./test_ft_lstiter.sh
./test_ft_memchr.sh
./test_ft_memcmp.sh
./test_ft_memcpy.sh
./test_ft_strjoin.sh
```

## How It Works

Each test typically follows this pattern:
1. **Compilation**: The shell script compiles a specialized "runner" C file along with the relevant `libft` source files.
2. **Execution**: The runner executes several test cases, including normal inputs and edge cases (e.g., `NULL`, empty strings, maximum/minimum values, zero lengths).
3. **Verification**: The runner compares the output of the `ft_` function with the expected behavior (often using the standard libc version as a reference).
4. **Reporting**: Results are displayed with ✅ for success and ❌ for failure.

## Adding New Tests
1. Create a new runner in `src/test_FUNCTION_runner.c`.
2. Create a corresponding shell script in `scripts/test_ft_FUNCTION.sh`.
3. Integrate the new script into `scripts/test_libft.sh`.
