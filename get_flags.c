#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format - A pointer to the formatted string in which to print the arguments
 * @i: A pointer to the current index in the formatted string
 * Return: Active flags
 */

int get_flags(const char *format, int *i)

{
	int m, curr_i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH,
	F_SPACE, 0};

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (m = 0; FLAGS_CH[m] != '\0'; m++)
			if (format[curr_i] == FLAGS_CH[m])
			{
				flags |= FLAGS_ARR[m];
				break;
			}
		if (FLAGS_CH[m] == 0)
			break;
	}

	*i = curr_i - 1;

	return (flags);
}
