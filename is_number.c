#include "main.h"

/**
 * is_number - checks if a char is a number
 * @k: Char to be evaluated
 *
 * Return: 1 if k is number, 0 otherwise
 */
int is_number(char k)
{
	if (k >= '0' && k <= '9')
		return (1);

	return (0);
}

