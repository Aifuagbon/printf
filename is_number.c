#include "main.h"

/**
 * is_printable - checks if a char is printable
 * @c: Char to be evaluated
 *
 * Return: 1 if c is printable, 0 otherwise
 */

int is_printable(char c)

{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - Append ascii in hexadecimal code to buffer
 * @buffer: Arrays of chars
 * @i: Index to start appending
 * @ascii_code: ASSCI code
 *
 * Return: Always 3
 */

int append_hexa_code(char ascii_code, char buffer[], int i)

{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= 1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - Verifies if a char is digit
 * @c: char evaluated
 *
 * Return:1 if c is digit, o otherwise
 */

int is_digit(char c)

{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}
