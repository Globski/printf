#include "main.h"

/**
 * handle_char - Handles the '%c' format specifier in the printf function.
 * @args: A va_list containing the arguments.
 * @count: A pointer to the character count.
 *
 * Description: This function retieves a character argument from va_list
 * and writes it to the output.
 */
void handle_char(va_list args, int *count)
{
	char c = va_arg(args, int);

	_putchar(c);
	(*count)++;
}

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

/**
 * handle_percent - Handles '%' in the printf function.
 * @count: pointer to the character count.
 */
void handle_percent(int *count)
{
	_putchar('%');
	(*count)++;
}
