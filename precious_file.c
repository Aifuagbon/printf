#include "main.h"

/**
 * precious_file - prints an argument based on its type.
 * @slg: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: ind.
 * @buffer: Buffer array to handle print.
 * @flags: calculates active flags.
 * @depth: get depth.
 * @precision: precision specification
 * @size: size specifier
 * Return: 1 or 2;
 */

int precious_file(const char *slg, int *ind, va_list list, char buffer[],
	int flags, int depth, int precision, int size)
{
	int i, value = 0, letters = -1;
	fmt_t slg_types[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"i", print_int},
		{"d", print_int},
		{"b", print_binary},
		{"u", print_unsigned},
		{"o", print_octal},
		{"x", print_hexadecimal},
		{"X", print_hexa_upper},
		{"p", print_pointer},
		{"S", print_non_printable},
		{"r", print_reverse},
		{"R", print_rot13string},
		{"\0", NULL}
	};

	for (i = 0; slg[i] != '\0'; i++)
		if (slg[*ind] == slg[i])
			return (slg_types[i].fn(list, buffer, flags, depth, precision, size));

	if (slg_types[i].fmt == NULL)
	{
		if (slg[*ind] == '\0')
			return (-1);
		value += write(1, "%%", 1);
		if (slg[*ind - 1] == ' ')
			value += write(1, " ", 1);
		else if (depth)
		{
			--(*ind);
			while (slg[*ind] != ' ' && slg[*ind] != '%')
				--(*ind);
			if (slg[*ind] == ' ')
				--(*ind);
			return (1);
		}
		value += write(1, &slg[*ind], 1);
		return (value);
	}
	return (letters);
}
