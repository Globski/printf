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
void handle_hex(va_list args, int *count, int upcase)
{
	unsigned int num = va_arg(args, unsigned int), hold, hold1;
	char *hexMemory;
	int i = 0, len;

	if (num == 0)
	{
		_putchar(48);
		(*count)++;
		return;
	}
	hold = num;
	len = 0;
	while (hold > 0)
	{
		len++;
		hold /= 16;
	}
	hexMemory = (char *)malloc(len + 1);
	if (hexMemory == NULL)
		return;
	while (num > 0)
	{
		int modulo = num % 16;

		if (modulo < 10)
			hexMemory[i] = modulo + 48;
		else
			hexMemory[i] = (upcase ? 'A' : 'a') + modulo - 10;
		num /= 16;
		i++;
	}
	hexMemory[i] = '\0';
	hold1 = len - 1;
	for (i = hold1; i >= 0; i--)
	{
		_putchar(hexMemory[i]);
		(*count)++;
	}
	free(hexMemory);
}

void handle_int(va_list args, int *count)
{
	int num = va_arg(args, int);
	int div = 1;

	if (args == NULL)
		return;
	if (num < 0)
	{
		_putchar('-');
		(*count)++;
		num = -num;
	}
	while ((num / div) > 9)
	{
		div *= 10;
	}
	while (div >= 1)
	{
		_putchar(((num / div) % 10) + '0');
		(*count)++;
		div /= 10;
	}
}

void handle_uint(va_list args, int *count)
{
	unsigned int num2 = va_arg(args, unsigned int);
	int div = 1;

	while ((num2 / div) > 9)
		div *= 10;
	while (div >= 1)
	{
		_putchar(((num2 / div) % 10) + 48);
		div /= 10;
		(*count)++;
	}
}

void handle_len_modifier(const char *format, va_list args, int *count, int *i)
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
    else if (format[*i] == 'o')
    {
        if (format[*i + 1] == 'l')
        {
            handle_octal(args, va_arg(args, unsigned long));
            (*i)++;
        }
        else if (format[*i + 1] == 'h')
        {
            handle_uint(args, va_arg(args, unsigned int));
            (*i)++;
        }
        else
        {
            handle_uint(args, count);
        }
    }
    else if (format[*i] == 'x')
    {
        if (format[*i + 1] == 'l')
        {
            print_long_unsigned_int(args, va_arg(args, unsigned long));
            (*i)++;
        }
        else if (format[*i + 1] == 'h')
        {
            handle_uint(args, va_arg(args, unsigned int));
            (*i)++;
        }
        else
        {
            handle_uint(args, count);
        }
    }
    else if (format[*i] == 'X')
    {
        if (format[*i + 1] == 'l')
        {
            print_long_unsigned_int(args, va_arg(args, unsigned long));
            (*i)++;
        }
        else if (format[*i + 1] == 'h')
        {
            print_short_unsigned_int(args, va_arg(args, unsigned int));
            (*i)++;
        }
        else
        {
            handle_uint(args, count);
        }
    }
}


		else
			handle_uint(args, count);
	}
}
