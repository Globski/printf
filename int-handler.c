#include "main.h"

/**
 * handle_int - Handles the '%d' or '%i' specifier in printf function.
 * @args: va_list containing arguments
 * @count: pointer to the number of characters.
 */
void handle_int(va_list args, int *count)
{
	int num = va_arg(args, int);
	int div = 1;

	if (num < 0)
	{
		_putchar('-');
		(*count)++;
		num = -num;
	}
	if (num == 0)
	{
		_putchar('0');
		(*count)++;
	}
	else
	{
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
}

/**
 * handle_uint - Hamdles the '%u' specifier in the printf function.
 * @args: va_list containing arguments.
 * @count: pointer to the number of characters.
 */
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
