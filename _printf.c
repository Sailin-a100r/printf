<<<<<<< HEAD
#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}

=======
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
>>>>>>> 586c7d60e52c4964fa2af7aa7f71a84316e1cf61
