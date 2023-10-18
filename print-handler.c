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
	else
	{
		_putchar('(');
		_putchar('n');
		_putchar('u');
		_putchar('l');
		_putchar('l');
		_putchar(')');
		(*count) += 6;
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

/**
 * handle_string_custom - Format and print a string with
 * non-printable characters
 *
 * @args: A va_list containing the string argument
 * @count: A pointer to the character count
 *
 * Description: This function takes a va_list containing a string
 * argument and prints the string while handling non-printable characters.
 * Non-printable characters (0 < ASCII value < 32 or >= 127 are printed as
 * '\x' followed by the ASCII code value in hexadecimal (always 2 characters).
 */
void handle_string_custom(va_list args, int *count)
{
	char *str = va_arg(args, char *);
	int i, modulo;

	if (str != NULL)
	{
		for (i = 0; str[i] != '\0'; i++)
		{
			if (str[i] < 32 || str[i] >= 127)
			{
				_putchar('\\');
				_putchar('x');
				_putchar((str[i] / 16) + '0');
				modulo = str[i] % 16;

				if (modulo < 10)
					_putchar(modulo + '0');
				else
					_putchar('A' + (modulo - 10));
				(*count) += 4;
			}
			else
			{
				_putchar(str[i]);
				(*count)++;
			}
		}
	}
}
