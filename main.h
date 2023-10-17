#ifndef MAIN_H
#define MAIN_H

/*
* Description: Header file containing prototypes for all functions
* used in the printf project.
*/

#include <stddef.h>
#include <stdarg.h>
#include <unistd.h>

int _putchar(char c);
void handle_string(va_list args, int *count);
void handle_char(va_list args, int *count);

#endif /* #ifndef MAIN_H */
