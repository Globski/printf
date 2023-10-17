# Printf Project - Custom `printf` Function

![License](https://img.shields.io/badge/license-MIT-blue.svg)

## Table of Contents

	- [Introduction](#introduction)
	- [Objectives](#objectives)
	- [Project Overview](#project-overview)
	- [Features](#features)
	- [Getting Started](#getting-started)
	- [Usage](#usage)
	- [Format Specifiers](#format-specifiers)
	- [Advanced Features](#advanced-features)
	- [Contributors](#contributors)
	- [License](#license)
- [Acknowledgments](#acknowledgments)

## Introduction

	Welcome to the Printf Project, where we implement a custom `printf` function in C. `_printf` is a custom implementation of the standard C library function `printf`. It provides a flexible and extensible way to format and print output in a wide variety of styles. The project follows the rules and guidelines set forth by ALX Africa and focuses on recreating the behavior of the standard C library `printf` function. its main goal is to help students understand the inner workings of the `printf` function.

## Objectives

	- Implement a custom `printf` function in C.
	- Handle various format specifiers and custom conversions.
	- Optimize buffer usage for efficient printing.

## Project Overview

	This project includes the following tasks:

	| Project | Description | Source Code |
	| --- | --- | --- |
	| **Task 0** | Write a function that produces output according to a format. | [Task 0 Source](task_0.c) |
	| **Task 1** | Handle the conversion specifiers `%d` and `%i`. | [Task 1 Source](task_1.c) |
	| **Task 2** | Implement the custom conversion specifier `%b` for binary. | [Task 2 Source](task_2.c) |
	| **Task 3** | Handle conversion specifiers `%u`, `%o`, `%x`, and `%X`. | [Task 3 Source](task_3.c) |
	| **Task 4** | Optimize buffer usage. | [Task 4 Source](task_4.c) |
	| **Task 5** | Add the custom specifier `%S` for non-printable characters. | [Task 5 Source](task_5.c) |
	| **Task 6** | Handle the conversion specifier `%p`. | [Task 6 Source](task_6.c) |
	| **Task 7** | Handle flag characters: `+`, space, `#`. | [Task 7 Source](task_7.c) |
	| **Task 8** | Handle length modifiers: `l` and `h`. | [Task 8 Source](task_8.c) |
	| **Task 9** | Handle field width. | [Task 9 Source](task_9.c) |
	| **Task 10** | Handle precision. | [Task 10 Source](task_10.c) |
	| **Task 11** | Handle the 0 flag character. | [Task 11 Source](task_11.c) |
	| **Task 12** | Handle the - flag character. | [Task 12 Source](task_12.c) |
	| **Task 13** | Implement the custom specifier `%r` for reversed strings. | [Task 13 Source](task_13.c) |
	| **Task 14** | Add the custom specifier `%R` for ROT13. | [Task 14 Source](task_14.c) |
	| **Task 15** | All the above options work well together. | [Task 15 Source](task_15.c) |

## Features

	- **Prototype:**
	- Prototype: `int _printf(const char *format, ...);`
	- `format` is a character string that can include conversion specifiers.
	- The function returns the number of characters printed (excluding the null byte used to end output to strings).
	```c
	/**
	 * _printf - Format and print output according to a format.
	 * @format: A character string containing format specifiers.
	 * @...: Additional arguments to replace format specifiers.
	 *
	 * Return: The number of characters printed.
	 */
	int _printf(const char *format, ...);
	```
	**Return value**
	- The _printf function returns an integer, which is the number of characters printed (excluding the null byte used to end output to strings). The return value checks how many characters were printed.

	- **Format String Arguments:**
	- The format string allows you to specify how the output should be formatted.
	- You can include various conversion specifiers (e.g., `%c`, `%s`, `%%`) and text.

	- The `format` argument is a character string containing format specifiers and text to be printed. For example:
	```c
	_printf("Hello, %s!", "World");
	```

	- **Flag Characters:**
	- Flag characters can be used with some conversion specifiers to modify the output. For example, `%+d` to display a positive number with a plus sign. For example:
	```c
	_printf("A positive number: %+d", 42);
	```

	- **Field Width:**
	- Field width specifies the minimum number of characters to be printed. For example, `%10s` to print a string in a field of width 10. For example:
	```c
	_printf("Width of 10: %10s", "Hello");
	```

	- **Precision:**
	- Precision controls the number of decimal places for floating-point numbers. For example, `%.2f` to print a floating-point number with two decimal places. For example:
	```c
	_printf("Two decimal places: %.2f", 3.14159);
	```

	- **Length Modifiers:**
	- Length modifiers specify the size of the data type to be printed. For example, `%ld` to print a long integer. For example:
	```c
	_printf("Long integer: %ld", 1234567890L);
	```

	- **Conversion Specifiers:**
	- Conversion specifiers define the data type of the argument to be printed. For example, `%c` for characters, `%s` for strings, `%d` for integers, and `%%` for a literal percent sign. For example:
	```c
	_printf("Character: %c, String: %s, Integer: %d", 'A', "Hello", 42);
	```

## Getting Started

	To get started with _printf, follow these simple steps:

	1. Clone this repository: `git clone https://github.com/YourUsername/printf.git`
	2. Compile the source code: `gcc *.c -o printf`
	3. Include the `main.h` header in your source code.
	4. Use `_printf` as you would the standard `printf` function in your program.

## Usage

	Here's an example of how to use `_printf`:

	```c
#include "main.h"

int main(void)
{
	int len;

	len = _printf("Hello, World!\n");
	return (0);
}
```


## Format Specifiers
Our custom printf function supports the following format specifiers:

- %c: Character
- %s: String
- %%: Percent
- %d and %i: Decimal and Integer
- %b: Binary (Custom)
- %u: Unsigned Integer
- %o: Octal
- %x and %X: Hexadecimal

## Tasks
### 0
- Implemented %c to print characters.
- Implemented %s to print strings.
- Implemented %% to print a literal '%' symbol.

### 1
- Added support for %d and %i to print integers.

### 2 (Advanced)
- Introduced %b to print integers in binary format.

### 3 (Advanced)
- Extended _printf to support %u, %o, %x, and %X for various integer formats.

### 4 (Advanced)
- Optimized by using a local buffer to minimize calls to the write function.

### 5 (Advanced)
- Implemented the custom %S conversion specifier, handling non-printable characters.

### 6 (Advanced)
- Added %p to print memory addresses.

### 7 (Advanced)
- Supported flag characters +, space, and # for non-custom conversion specifiers.

### 8 (Advanced)
- Extended functionality to handle length modifiers l and h.

### 9 (Advanced)
- Introduced field width support for non-custom conversion specifiers.

### 10 (Advanced)
- Implemented precision for non-custom conversion specifiers.

### 11 (Advanced)
- Added support for the 0 flag character for non-custom conversion specifiers.

### 12 (Advanced)
- Supported the - flag character for non-custom conversion specifiers.

### 13 (Advanced)
- Introduced the custom %r conversion specifier to reverse strings.

### 14 (Advanced)
- Implemented %R to perform ROT13 on strings.

### 15 (Advanced)
- Ensured that all options work well together.

## Advanced Features
Our custom printf function includes several advanced features:

- Handling flag characters: +, space, and #
- Handling length modifiers: l and h
- Handling field width
- Handling precision
- Handling flag character 0
- Handling flag character -
- Custom specifier for non-printable characters %S
- Custom specifier for reversed string %r
- Custom specifier for ROT13 %R

## Contributors

This project is maintained by the following contributors:

- [Ogunsemore Gloria](https://github.com/Globski)
- [Emmanuel Ifediora](https://github.com/Manuelshub)

## License

This project is open source and available under the [MIT License](LICENSE).

## Acknowledgments

The `_printf` function emulates the functionality of the C standard library function `printf`.
We would like to express our sincere gratitude to [ALX Afica](https://www.alxafrica.com/) for providing the educational environment and guidance that enabled the development of this project.

ALX Afica is a renowned full-stack software engineering program that prepares students for successful careers in the tech industry through project-based peer learning and a dedication to excellence. The project was created as part of the ALX Afica curriculum, and we want to acknowledge the institution for its invaluable support and resources.

For more information about ALX Afica and its programs, please visit this [link](https://www.alxafrica.com/).
