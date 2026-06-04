# C++ - Module 06
## C++ casts

**Summary:** This document contains the exercises for Module 06 of the C++ modules.  
**Version:** 8.0

---

## Contents

- I Introduction
- II General rules
- III Additional Rule
- IV AI Instructions
- V Exercise 00: Conversion of scalar types
- VI Exercise 01: Serialization
- VII Exercise 02: Identify real type
- VIII Submission and Peer Evaluation

---

# Chapter I - Introduction

C++ is a general-purpose programming language created by Bjarne Stroustrup as an extension of the C programming language, often referred to as "C with Classes" (source: Wikipedia).

The goal of these modules is to introduce you to Object-Oriented Programming.

This will be the starting point of your C++ journey. Many languages are recommended for learning OOP, but we chose C++ since it is derived from your old friend, C. As C++ is a complex language, your code will adhere to the C++98 standard to keep things simple.

We acknowledge that modern C++ differs significantly in many aspects. If you want to become a proficient C++ developer, it will be up to you to explore further beyond the 42 Common Core!

---

# Chapter II - General rules

## Compiling

- Compile your code with `c++` and the flags `-Wall -Wextra -Werror`
- Your code should still compile if you add the flag `-std=c++98`

## Formatting and naming conventions

- The exercise directories will be named this way: `ex00`, `ex01`, ..., `exn`
- Name your files, classes, functions, member functions and attributes as required in the guidelines.
- Write class names in UpperCamelCase format.
- Unless specified otherwise, every output message must end with a newline character and be displayed to the standard output.
- No coding style is enforced in the C++ modules, but code should remain clean and readable.

## Allowed / Forbidden

- Use of the standard library is generally allowed.
- External libraries are forbidden.
- C++11 and newer features are forbidden.
- Boost libraries are forbidden.
- The following functions are forbidden:
  - `printf()`
  - `alloc()` family
  - `free()`

Additional restrictions:

- `using namespace <ns_name>` is forbidden unless explicitly stated otherwise.
- `friend` is forbidden unless explicitly stated otherwise.
- STL containers and algorithms are forbidden until Modules 08 and 09.

## Design requirements

- Avoid memory leaks.
- From Module 02 to Module 09, classes must follow the Orthodox Canonical Form unless explicitly stated otherwise.
- Function implementations inside header files (except templates) result in a grade of 0.
- Headers must be self-sufficient and protected against double inclusion.

## Read me

- Additional files may be added if necessary.
- Examples may contain requirements not explicitly written.
- Read the entire module before starting.
- Use your brain and learn the theoretical concepts.

---

# Chapter III - Additional Rule

For each exercise, type conversion must be handled using a specific type of casting.

Your choice will be reviewed during the defense.

---

# Chapter IV - AI Instructions

## Context

This project is designed to help you discover the fundamental building blocks of your ICT training.

True foundational learning requires genuine intellectual effort through challenge, repetition and peer-learning exchanges.

## Main message

- Build strong foundations without shortcuts.
- Develop technical and problem-solving skills.
- Learn through peer collaboration.
- The learning journey matters more than the result.
- Learn the risks associated with AI and how to mitigate them.

## Learner rules

- Apply your own reasoning before turning to AI.
- Do not ask AI for direct answers.
- Learn the 42 global approach on AI.

## Expected outcomes

- Build solid coding foundations.
- Understand why AI can be dangerous during foundational learning.

## Examples

### Good practice

"I'm stuck on a new concept. I ask someone nearby how they approached it. We talk for 10 minutes — and suddenly it clicks."

### Bad practice

"I secretly use AI, copy some code that looks right. During peer evaluation, I can't explain anything. I fail."

---

# Chapter V - Exercise 00: Conversion of scalar types

**Turn-in directory:** `ex00/`

**Files to turn in:**

- Makefile
- *.cpp
- *.{h,hpp}

**Allowed functions:** Any function that converts a string to an int, float or double.

Implement a class:

```cpp
class ScalarConverter
```

It must contain only one static method:

```cpp
static void convert(std::string literal);
```

The method receives a string representation of a C++ literal and outputs:

- char
- int
- float
- double

The class must not be instantiable.

Supported literals:

### char

Examples:

```text
'c'
'a'
```

### int

```text
0
-42
42
```

### float

```text
0.0f
-4.2f
4.2f
```

Pseudo literals:

```text
-inff
+inff
nanf
```

### double

```text
0.0
-4.2
4.2
```

Pseudo literals:

```text
-inf
+inf
nan
```

Requirements:

1. Detect the literal type.
2. Convert the string to its real type.
3. Explicitly convert it to the three remaining scalar types.
4. Display results.

If a conversion is impossible or overflows, display an informative message.

Example:

```text
./convert 0

char: Non displayable
int: 0
float: 0.0f
double: 0.0
```

```text
./convert nan

char: impossible
int: impossible
float: nanf
double: nan
```

```text
./convert 42.0f

char: '*'
int: 42
float: 42.0f
double: 42.0
```

---

# Chapter VI - Exercise 01: Serialization

**Turn-in directory:** `ex01/`

**Files to turn in:**

- Makefile
- *.cpp
- *.{h,hpp}

**Forbidden functions:** None

Implement a class:

```cpp
class Serializer
```

The class must not be instantiable.

Static methods:

```cpp
uintptr_t serialize(Data* ptr);
```

Converts a pointer into an unsigned integer of type `uintptr_t`.

```cpp
Data* deserialize(uintptr_t raw);
```

Converts an unsigned integer back into a pointer.

Requirements:

- Create a non-empty `Data` structure.
- Serialize the address of a `Data` object.
- Deserialize the returned value.
- Verify that the resulting pointer equals the original pointer.

Do not forget to submit the files related to the `Data` structure.

---

# Chapter VII - Exercise 02: Identify real type

**Turn-in directory:** `ex02/`

**Files to turn in:**

- Makefile
- *.cpp
- *.{h,hpp}

**Forbidden functions:**

```cpp
std::typeinfo
```

Implement:

```cpp
class Base
```

with only a public virtual destructor.

Create:

```cpp
class A : public Base {};
class B : public Base {};
class C : public Base {};
```

These classes do not need Orthodox Canonical Form.

Functions to implement:

```cpp
Base* generate(void);
```

Randomly creates A, B or C and returns a `Base*`.

```cpp
void identify(Base* p);
```

Prints the real type: A, B or C.

```cpp
void identify(Base& p);
```

Prints the real type: A, B or C.

Using a pointer inside the reference version is forbidden.

Including `<typeinfo>` is forbidden.

Write a test program demonstrating everything works correctly.

---

# Chapter VIII - Submission and Peer Evaluation

Submit your project to your Git repository.

Only files present in the repository will be evaluated.

During evaluation, a small modification may be requested, such as:

- A small behavior change
- Writing a few lines of code
- Refactoring a small section
- Adding a simple feature

The goal is to verify understanding of the project.

The modification should be achievable in a few minutes.
