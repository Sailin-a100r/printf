#include <unistd.h>
#include "main.h"

/**
 * print_char - function that prints a charcter to
 * the standard output.
 *
 * @character: the character to print
 *
 * Return: 0 Success, -1 otherwise
 */

void print_char(char character)
{
	if (character)
	{
		write(1, &character, 1);
		return (0);
	}
	return (-1);
}
