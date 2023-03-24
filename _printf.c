#include "main.h"
#include <stdarg.h>

/**
 * _printf - function that produces output according to a format
 *
 * @format: string of specified format
 * @...: additional arguments
 *
 * Return: 0 success, -1 otherwise
 */

int _printf(const char *format, ...)
{
	va_list args;
	int i;
	char c;
	char *s;

	if (format == NULL)
		return (-1);
	i = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				c = va_arg(args, int);
				_putchar(c);
				i++;
				continue;
			}
			else if (format[i] == 's')
			{
				s = va_arg(args, char *);
				_printf(s);
				i++;
				continue;
			}
			else
			{
				i++;
				continue;
			}
		}
		_putchar(format[i]);
		i++;
	}

	va_end(args);
	return (0);
}
