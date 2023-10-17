#include "main.h"

/**
 * _putchar - writes a character to stdout.
 * @c: the chacter to be printed.
 * Return: 0 on success.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
