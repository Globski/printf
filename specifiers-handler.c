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
		handle_integer_or_long(args, count, format, i);
	else if (format[*i] == 'u')
		handle_unsigned(args, count, format, i);
	else if (format[*i] == 'b')
		handle_binary(args, count);
	else if (format[*i] == 'o')
		handle_octal(args, count);
	else if (format[*i] == 'x')
		handle_hex(args, count, 0);
	else if (format[*i] == 'X')
		handle_hex(args, count, 1);
	else if (format[*i] == 'p')
		handle_pointer(args, count);
	else if (format[*i] == 'S')
		handle_string_custom(args, count);
	else
	{
		_putchar('%');
		_putchar(format[*i]);
		(*count) += 2;
	}
}

/**
 * handle_unsigned - Handles the 'u' format specifier, which can be
 * 'u' or 'ull'.
 * @args: The va_list containing the arguments.
 * @count: A pointer to the character count.
 * @format: The format string being processed.
 * @i: A pointer to the current position in the format string.
 */
void handle_unsigned(va_list args, int *count, const char *format, int *i)
{
	if (format[*i + 1] == 'l' && format[*i + 2] == 'l')
	{
		handle_long_unsigned(args, count);
		(*i) += 2;
	}
	else
		handle_unsigned_int(args, count);
}

/**
 * handle_integer_or_long - Handles the 'd' and 'i' format specifiers, which can be 'd', 'i', or 'll'.
 * @args: The va_list containing the arguments.
 * @count: A pointer to the character count.
 * @format: The format string being processed.
 * @i: A pointer to the current position in the format string.
 */
void handle_integer_or_long(va_list args, int *count, const char *format, int *i)
{
	if (format[*i + 1] == 'l')
	{
		handle_long_int(args, count);
		(*i)++;
	}
	else
		handle_integer(args, count);
}
