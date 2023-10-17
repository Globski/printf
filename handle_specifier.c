#include "main.h"

/**
 * handle_specifier - Handle format specifiers in the printf function.
 * @format: The format string being processed.
 * @args: The va_list containing the arguments.
 * @count: A pointer to the character count.
 * @i: A pointer to the current position in the format string.
 */
void handle_specifier(const char *format, va_list args, int *count, int *i)
{
	if (format[*i] == 'c')
		handle_char(args, count);
	else if (format[*i] == 's')
		handle_string(args, count);
	else if (format[*i] == '%')
		handle_percent(count);
	else if (format[*i] == 'd' || format[*i] == 'i')
		handle_int(args, count);
	else if (format[*i] == 'b')
		handle_binary(args, count);
	else if (format[*i] == 'u')
		handle_uint(args, count);
	else
	{
		_putchar('%');
		_putchar(format[*i]);
		(*count) += 2;
	}
}
