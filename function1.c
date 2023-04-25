#include "main.h"

/**TO PRINT UNSIGNED NUMBER */
/**
 * print_unsigned - This is a function that prints an unsigned number
 * @types: arguments list passed to the function
 * @buffer: array to handle print
 * @flags:  Computes active flags
 * @width: Specifies the width
 * @precision: Precision specification
 * @size: Specifies the size
 * Return: The amount of chars printed
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int x = BUFF_SIZE - 2;
	unsigned long int val = va_arg(types, unsigned long int);

	val = convert_size_unsgnd(val, size);

	if (val == 0)
		buffer[x--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (val > 0)
	{
		buffer[x--] = (val % 10) + '0';
		val /= 10;
	}

	x++;

	return (write_unsgnd(0, x, buffer, flags, width, precision, size));
}

/**TO PRINT UNSIGNED NUMBER IN OCTAL NOTATION*/
/**
 * print_octal - function that prints an unsigned number
 * in octal notation
 * @types: list of arguments passed to the function
 * @buffer: array to handle print
 * @flags:  Computes active flags
 * @width: Specifies the width
 * @precision: Precision specification
 * @size: Specifies the size
 * Return: The amount of chars printed
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int x = BUFF_SIZE - 2;
	unsigned long int val = va_arg(types, unsigned long int);
	unsigned long int init_val = val;

	UNUSED(width);

	val = convert_size_unsgnd(val, size);

	if (val == 0)
		buffer[x--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (val > 0)
	{
		buffer[x--] = (val % 8) + '0';
		val /= 8;
	}

	if (flags & F_HASH && init_val != 0)
		buffer[x--] = '0';

	x++;

	return (write_unsgnd(0, x, buffer, flags, width, precision, size));
}

/**TO PRINT UNSIGNED NUMBER IN HEXADECIMAL NOTATION*/
/**
 * print_hexadecimal - function that prints an unsigned number
 * in hexadecimal notation
 * @types: arguments lists passed to the function
 * @buffer: array to handle print
 * @flags:  Computes active flags
 * @width: Specifies the width
 * @precision: Precision specification
 * @size: Specifies the size
 * Return: The amount of chars printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**TO PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL NOTATION*/
/**
 * print_hexa_upper - function that prints an unsigned number
 * in upper hexadecimal notation
 * @types: arguments lists passed to the function
 * @buffer: array to handle print
 * @flags:  Computes active flags
 * @width: Specifies the width
 * @precision: Precision specification
 * @size: Specifies the size
 * Return: The amount of chars printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/** TO PRINT HEXADECIMAL NUMBERS IN LOWERCASE OR UPPERCASE */
/**
 * print_hexa - prints a hexadecimal
 * number in lowercase or uppercase
 * @types: list of arguments passed to the function
 * @buffer: array to handle print
 * @flags:  Computes active flags
 * @flag_ch: Calculates active flags
 * @map_to: Array of values to map the number to
 * @width: Specifies the width
 * @precision: Precision specification
 * @size: Specifies the size
 * Return: The amount of chars printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int x = BUFF_SIZE - 2;
	unsigned long int val = va_arg(types, unsigned long int);
	unsigned long int init_val = val;

	UNUSED(width);

	val = convert_size_unsgnd(val, size);

	if (val == 0)
		buffer[x--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (val > 0)
	{
		buffer[x--] = map_to[val % 16];
		val /= 16;
	}

	if (flags & F_HASH && init_val != 0)
	{
		buffer[x--] = flag_ch;
		buffer[x--] = '0';
	}

	x++;

	return (write_unsgnd(0, x, buffer, flags, width, precision, size));
}
