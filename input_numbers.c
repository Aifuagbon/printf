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
	int length = BUFF_SIZE - age - 1;
	char letter = ' ', extra_ch = 0;
	char padd;

	if ((bottles & F_ZERO) && !(bottles & F_MINUS))
		padd = '0';
	if (is_odd)
		extra_ch = '-';
	else if (bottles & F_PLUS)
		extra_ch = '+';
	else if (bottles & F_SPACE)
		extra_ch = ' ';

	int num_chars = write_num(age, buffer, bottles, depth, precision,
		length, letter, extra_ch);

	return (num_chars);
}
