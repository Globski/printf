#include "main.h"
/**
 * handle_hex - Handles the %x and %X conversion specifiers.
 * @args: The va_list containing the argument.
 * @count: A pointer to the character count.
 * @upcase: A flag to specify whether the output should be in
 * uppercase (if non-zero) or lowercase (if zero).
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
