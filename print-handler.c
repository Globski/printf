#include "main.h"

/**
 * handle_string - Handles the '%s' format specifier in the printf function.
 * @args: A va_list containing the arguments.
 * @count: A pointer to the character count.
 *
 * Description: This function retrieves a string argument from va_list and
 * writes each character to the output while incrementing the count.
 */

void handle_string(va_list args, int *count)
{
	char *str = va_arg(args, char *);
	int i;

	if (str != NULL)
	{
		for (i = 0; str[i] != '\0'; i++)
		{
			_putchar(str[i]);
			(*count)++;
		}
	}
}


