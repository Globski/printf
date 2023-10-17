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
