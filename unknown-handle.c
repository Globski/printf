#include "main.h"
/**
 * handle_unknown - Handles an unknown conversion specifier.
 *
 * Description: This function is called when an unknown conversion specifier
 * is encountered in the format string. It simply prints the '%' character
 * followed by the unknown specifier.
 *
 * @format: A pointer to the format string.
 * @args: The va_list containing the arguments.
 * @count: A pointer to the character count.
 * @i: A pointer to the current position in the format string.
 */
void handle_unknown(const char *format, va_list args __attribute__((unused)), int *count, int *i)
{
	_putchar('%');
	_putchar(format[*i]);
	(*count) += 2;
}
