#include "main.h"

/**
 * convert_size_unsgnd - sets a value to the specified size
 * @val: value to be casted
 * @size: value indicating the type to be set
 *
 * Return: Casted figure of val
 */

long int convert_size_unsgnd(unsigned long int val, int size)
{
	if (size == S_LONG)
		return (val);
	else if (size == S_SHORT)
		return ((unsigned short)val);

	return ((unsigned int)val);
}


