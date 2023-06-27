#include "main.h"

/**
 * input_pointer- Write a memory address
 * @buffer: Arrays of chars
 * @val: value at which the number starts in the buffer
 * @depth: depth of number
 * @width: Width specifier
 * @pen: pen specifier
 * @padd: Char representing the padding
 * @extra_k: Char representing extra char
 * @padd_start: Index at which padding should start
 *
 * Return: Number of written chars.
 */
int input_pointer(char buffer[], int val, int depth,
	int width, int pen, char padd, char extra_k, int padd_start)
{
	int i;

	if (width > depth)
	{
		for (i = 2; i < width - depth + 2; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (pen & F_MINUS && padd == ' ')/* Asign extra char to left of buffer */
		{
			buffer[--val] = 'x';
			buffer[--val] = '0';
			if (extra_k)
				buffer[--val] = extra_k;
			return (write(1, &buffer[val], depth) + write(1, &buffer[2], i - 2));
		}
		else if (!(pen & F_MINUS) && padd == ' ')/* extra char to left of buffer */
		{
			buffer[--val] = 'x';
			buffer[--val] = '0';
			if (extra_k)
				buffer[--val] = extra_k;
			return (write(1, &buffer[2], i - 2) + write(1, &buffer[val], depth));
		}
		else if (!(pen & F_MINUS) && padd == '0')/* extra char to left of padd */
		{
			if (extra_k)
				buffer[--padd_start] = extra_k;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], i - padd_start) +
				write(1, &buffer[val], depth - (1 - padd_start) - 2));
		}
	}
	buffer[--val] = 'x';
	buffer[--val] = '0';
	if (extra_k)
		buffer[--val] = extra_k;
	return (write(1, &buffer[val], BUFF_SIZE - val - 1));
}



