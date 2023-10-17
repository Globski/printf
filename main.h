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

#endif /* #ifndef MAIN_H */
