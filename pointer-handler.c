#include "main.h"

/**
 * handle_pointer - Format and print a pointer.
 * @args: A va_list containing the pointer to be printed.
 * @count: A pointer to the count of characters printed.
 */
void handle_pointer(va_list args, int *count)
{
	void *ptr = va_arg(args, void *);
	unsigned long num;
	char hex_nums[];
	int i;

	if (ptr != NULL)
	{
		_putchar('0');
		_putchar('x');
		(*count) += 2;
		num = (unsigned long)ptr;
		hex_nums[] = "0123456789abcdef";

		int flagStart = 0;

		for (i = (sizeof(void *) * 2) - 1; i >= 0; i--)
		{
			int digit = (num >> (i * 4)) & 0xf;

			if (digit != 0 || flagStart)
			{
				_putchar(hex_nums[digit]);
				(*count)++;
				flagStart = 1;
			}
		}
	}
	else
	{
		char nil[] = "(nil)";

		for (i = 0; nil[i]; i++)
		{
			_putchar(nil[i]);
			(*count)++;
		}
	}
}
