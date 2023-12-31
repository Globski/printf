#include "main.h"

/**
 * _printf - Custom printf function that handles %c, %s, and %%.
 * @format: The format string to be printed.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0, i;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == ' ' || !format[i])
				return (-1);
			else if (format[i] != '\0')
			{
				handle_specifier(format, args, &count, &i);
			}
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
	}
	va_end(args);
	return (count);
}
