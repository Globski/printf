#include "main.h"

/**
 * handle_short_int - Handles and prints a short integer argument
 * @args: A va_list of arguments
 * @count: A pointer to the character count
 *
 * Description: This function extracts a short integer from va_list
 * args, converts it to a string, and prints it. If the integer is
 * negative, it adds a '-' sign to the output.
 */
void handle_short_int(va_list args, int *count)
{
	short num = va_arg(args, int);
	int div = 1;

	if (num < 0)
	{
		_putchar('-');
		(*count)++;
		num = -num;
	}

	while (num / div > 9)
	{
		div *= 10;
	}

	while (div >= 1)
	{
		_putchar((num / div) % 10 + 48);
		(*count)++;
		div /= 10;
	}
}

/**
 * handle_short_unsigned_int - Handles and prints a short unsigned
 * integer argument
 * @args: A va_list of arguments
 * @count: A pointer to the character count
 *
 * Description: This function extracts a short unsigned integer from
 * va_list args, converts it to a string, and prints it.
 */
void handle_short_unsigned_int(va_list args, int *count)
{
	unsigned short num = va_arg(args, int);
	int div = 1;

	while (num / div > 9)
	{
		div *= 10;
	}

	while (div >= 1)
	{
		_putchar((num / div) % 10 + 48);
		(*count)++;
		div /= 10;
	}
}

/**
 * handle_long_unsigned_int - Handles and prints a long unsigned
 * integer argument
 * @args: A va_list of arguments
 * @count: A pointer to the character count
 *
 * Description: This function extracts a long unsigned integer from
 * va_list args, converts it to a string, and prints it.
 */
void handle_long_unsigned_int(va_list args, int *count)
{
	unsigned long num = va_arg(args, unsigned long);
	unsigned long div = 1;

	while (num / div > 9)
	{
		div *= 10;
	}

	while (div >= 1)
	{
		_putchar((num / div) % 10 + 48);
		(*count)++;
		div /= 10;
	}
}

/**
 * handle_long_int - Handles and prints a long integer argument
 * @args: A va_list of arguments
 * @count: A pointer to the character count
 *
 * Description: This function extracts a long integer from va_list args,
 * converts it to a string, and prints it. It also handles negative values.
 */
void handle_long_int(va_list args, int *count)
{
	long num = va_arg(args, long);
	int div = 1;

	if (num < 0)
	{
		_putchar('-');
		(*count)++;
		num = -num;
	}

	while (num / div > 9)
	{
		div *= 10;
	}

	while (div >= 1)
	{
		_putchar((num / div) % 10 + 48);
		(*count)++;
		div /= 10;
	}
}
