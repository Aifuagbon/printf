#include "main.h"

/**
 * change_size_number - set a figure to the specified size
 * @fig: figure to be set.
 * @size: figure indentifying the type to be set.
 *
 * Return: set value of fig
 */
long int change_size_number(long int fig, int size)
{
	if (size == S_LONG)
		return (fig);
	else if (size == S_SHORT)
		return ((short)fig);

	return ((int)fig);
}

