#include "main.h"

/**
 * handle_write_char - Prints a string
 * @c: char types
 * @buffer: Buffer array to write print
 * @flags: Calculates active flags
 * @width: get width
 * @precision: precision specification
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */

int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size)

{
	int i = 0;
	char book = ' ';
	
	UNUSED(precision);
	UNUSED(size);
	
	if (flags & F_ZERO)
		book = '0';
	
	buffer[i++] = c;
	buffer[i] = '\0';
	
	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFF_SIZE - i - 2] = book;
		
		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1) +
					write(1, &buffer[0], 1));
	}
	
	return (write(1, &buffer[0], 1));
}

/**
 * write_unsgnd - Writes an unsigned number
 * @is_negative: Number indicating if num is negative
 * @ind: Index at which number starts in the buffer
 * @buffer: Array of chars
 * @flags: flags specifier
 * @width: width specifier
 * @precision: precision specifier
 *
 * Return: Number of written chars
 */

int write_unsgnd(int is_negative, int ind,
		char buffer[],
		int flags, int width, int precision, int size)

{
	int length = BUFF_SIZE - ind - 1, i = 0;
	char padd = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0);

	if (precision > 0 && precision < length)
		padd = ' ';

	while (precision > length)
	{
		buffer[--ind] = '0';
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';

	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			buffer[i] = padd;


		buffer[i] = '\0';

		if (flags & F_MINUS)
		{
			return (write(1, &buffer[ind], length) + write(1, &buffer[0], i));
		}
		else
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[ind], length));
		}
	}

	return (write(1, &buffer[ind], length));
}

/**
 * write_number - string is printed
 * @is_negative: arguments listed
 * @ind: types char
 * @buffer: array buffer to handle print
 * @flags: active flags calculated
 * @width: width to get
 * @precision: specifier for precision
 * @size: specifier for size
 *
 * Return: Number of chars printed
 */

int write_number(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size)

{
	int length = BUFF_SIZE - ind - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';

	return (write_num(ind, buffer, flags, width, precision,
			length, padd, extra_ch));
}
