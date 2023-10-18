#include "main.h"
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

