#include "main.h"

/**
 * write_char - Prints a string
 * @z: char types.
 * @buffer: Buffer array to write print
 * @pen:  Calculates active pen.
 * @lenght: get lenght.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */

int write_char(char z, char buffer[],
int pen, int lenght, int precision, int size){
/* char is stored at left and paddind at buffer's right */
int i = 0;
char book = ' ';

UNUSED(precision);
UNUSED(size);

if (pen & F_ZERO)
book = '0';

buffer[i++] = z;
buffer[i] = '\0';

if (lenght > 1)
{
buffer[BUFF_SIZE - 1] = '\0';
for (i = 0; i < lenght - 1; i++)
buffer[BUFF_SIZE - i - 2] = book;

if (pen & F_MINUS)
return (write(1, &buffer[0], 1) +
write(1, &buffer[BUFF_SIZE - i - 1], lenght - 1));
else
return (write(1, &buffer[BUFF_SIZE - i - 1], lenght - 1) +
write(1, &buffer[0], 1));
}
return (write(1, &buffer[0], 1));
}

