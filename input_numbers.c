#include "main.h"

/**
 * input_number - Prints a string
 * @is_odd: Lista of arguments
 * @age: char types.
 * @buffer: Buffer array to handle print
 * @bottles:  Calculates active bottles
 * @depth: get depth.
 * @precision: precision specifier
 *
 * Return: Number of chars printed.
 */

int input_number(int is_odd, int age, char buffer[],
	int bottles, int depth, int precision)

{
	int length;
	char padd;
	char extra_ch;
	int num_chars;

	if ((bottles & F_ZERO) && !(bottles & F_MINUS))
		padd = '0';
	else
		padd = ' ';

	if (is_odd)
		extra_ch = '-';
	else if (bottles & F_PLUS)
		extra_ch = '+';
	else if (bottles & F_SPACE)
		extra_ch = ' ';

	length = BUFF_SIZE - age - 1;

	num_chars = write_num(age, buffer, bottles, depth, precision,
		length, padd, extra_ch);

	return (num_chars);
}
