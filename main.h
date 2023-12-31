#ifndef MAIN_H
#define MAIN_H

/*
* Description: Header file containing prototypes for all functions
* used in the printf project.
*/

#include <stddef.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int _putchar(char c);
void handle_string(va_list args, int *count);
void handle_char(va_list args, int *count);
void handle_percent(int *count);
int _printf(const char *format, ...);
void handle_specifier(const char *format, va_list args, int *count, int *i);
void handle_int(va_list args, int *count);
void handle_uint(va_list args, int *count);
void print_binary(unsigned int num, int *count);
void handle_binary(va_list args, int *count);
void handle_hex(va_list args, int *count, int upcase);
void print_octal(unsigned int n, int *count);
void handle_octal(va_list args, int *count);
void handle_pointer(va_list args, int *count);
void handle_string_custom(va_list args, int *count);
void handle_short_int(va_list args, int *count);
void handle_short_unsigned_int(va_list args, int *count);
void handle_long_int(va_list args, int *count);
void handle_long_unsigned_int(va_list args, int *count);
void handle_len_modifier(const char *format, va_list args, int *count, int *i);

#endif /* #ifndef MAIN_H */
