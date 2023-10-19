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
	else if (format[*i] == 'd' || format[*i] == 'i' || format[*i] == 'u')
		handle_len_modifier(format, args, count, i);
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
 * handle_len_modifier - Handles length modifier for numeric specifiers.
 * @format: The format string being processed.
 * @args: The va_list containing the arguments.
 * @count: A pointer to the character count.
 * @i: A pointer to the current position in the format string.
 *
 * Description: This function processes the length modifier for
 * numeric specifiers, such as 'd' and 'u'. It determines whether to
 * use long or short variants of the specifiers based on the format string.
 */
void handle_length_modifier(const char *format, va_list args, int *count, int *i)
{
	if (format[*i] == 'd' || format[*i] == 'i')
	{
		if (format[*i + 1] == 'l')
		{
			print_long_int(args, count);
			(*i)++;
		}
		else if (format[*i + 1] == 'h')
		{
			print_short_int(args, count);
			(*i)++;
		}
		else
			handle_int(args, count);
	}
	else if (format[*i] == 'u')
	{
		if (format[*i + 1] == 'l')
		{
			print_long_unsigned_int(args, count);
			(*i)++;
		}
		else if (format[*i + 1] == 'h')
		{
			print_short_unsigned_int(args, count);
			(*i)++;
		}
		else
			handle_uint(args, count);
	}
}
