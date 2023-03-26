#include <stdlib.h>
#include "main.h"
#include <stdarg.h>
/**
 * _printf - function that produces output according to a format
 *
 * @format: string with format specifiers
 *
 * @Return: 0 Success, -1 otherwise
 */

int _printf(const char *format, ...)
{
	va_list arguments;
	int i;

	va_start(arguments, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				print_char(va_arg(arguments, int));
				i++;
				continue;
			}
			else if (format[i] == 's')
			{
				_printf(va_arg(arguments, char *));
				i++;
				continue;
			}
			else
			{
				_printf("Error\n");
				return (-1);
			}
		}
		print_char(format[i]);
		i++;
	}
	va_end(arguments);
	return (0);
}
