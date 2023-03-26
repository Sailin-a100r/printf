#include <stdlib.h>
#include "main.h"
#include <stdarg.h>
/**
 * _printf - function that produces output according to a format
 *
 * @format: string with format specifiers
 *
 * Return: 0 Success, -1 otherwise
 */

int _printf(const char *format, ...)
{
	va_list arguments;
	int i;
	char *string, character;

	if (format == NULL)
		return (-1);
	va_start(arguments, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
			{
				character = va_arg(arguments, int);
				if (!character)
				{
				print_char(character);
				i = i + 2;
				continue;
				}
			}
			else if (format[i + 1] == 's')
			{
				string = va_arg(arguments, char *);
				if (string == NULL)
					string = "(null)";
				_printf(string);
				i = i + 2;
				continue;
			}
			else
			{
				return (-1);
			}
		}
		print_char(format[i]);
		i++;
	}
	va_end(arguments);
	return (0);
}
