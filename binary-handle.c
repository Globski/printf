#include "main.h"

/**
 * print_binary - Prints an unsigned integer in binary format.
 * @num: The unsigned integer to be printed in binary.
 * @count: A pointer to the character count.
 */
void print_binary(unsigned int num, int *count)
{
	if (num > 1)
		print_binary(num / 2, count);

	_putchar((num % 2) + 48);
	(*count)++;
}

/**
 * handle_binary - Handles the %b conversion specifier.
 * @args: The va_list containing the argument.
 * @count: A pointer to the character count.
 */
void handle_binary(va_list args, int *count)
{
	unsigned int num = va_arg(args, unsigned int);

	print_binary(num, count);
}

/**
 * print_octal - prints an unsigned number in base 8.
 * @n: the number to be printed in base 8.
 * @count: pointer to the number of characters.
 */
void print_octal(unsigned int n, int *count)
{
	int i = 0;
	char ptr[32];

	if (n == 0)
	{
		_putchar('0' + 0);
		(*count)++;
	}
	while (n > 0)
	{
		ptr[i] = (n % 8) + 48;
		n /= 8;
		i++;
	}
	while (i > 0)
	{
		_putchar(ptr[i - 1]);
		(*count)++;
		i--;
	}
}

/**
 * handle_octal - Handles the %o specifier in the printf function
 * @args: va_list containing the argument.
 * @count: pointer to the number of characters.
 */
void handle_octal(va_list args, int *count)
{
	unsigned int n = va_arg(args, unsigned int);

	print_octal(n, count);
}
