#include "main.h"

/**
 * is_printable - is given char printable
 * @c: Char to check if printable
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
 * append_hexa_code - include ASCCI in hexadecimal code at the end f the buffer
 * @buffer: Array of characters
 * @i: where to start changing
 * @ascii_code: ASSCI CODE.
 * Return: 3 on success
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - check if given character is a digit
 * @r: Char tocalculate
 *
 * Return: 1 if r is a digit, 0 otherwise
 */
int is_digit(char c)
{
	if (r >= '0' && r <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - Casts a number to the specified size
 * @num: No. to cast
 * @size: No. indicating the type to be casted.
 *
 * Return: Casted value of num
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - Casts a number to the specified size
 * @num: indicates type to cast
 * @size: Number indicating the type to be casted
 *
 * Return: Casted value
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
