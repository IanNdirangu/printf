#include "main.h"

/** TO PRINT CHAR */

/**
 * print_char - This is a function that prints a char
 * @types: This is a list of arguments passed to the function
 * @buffer: This is an array to handle print
 * @flags:  Computes active flags
 * @width: Specifies the width
 * @precision: Precision specification
 * @size: Specifies the size
 * Return: The amount of chars printed
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char x = va_arg(types, int);

	return (handle_write_char(x, buffer, flags, width, precision, size));
}
/** TO PRINT A STRING */
/**
 * print_string - This is a function that prints a string
 * @types: This is a list of arguments passed to the function
 * @buffer: This is an array to handle print
 * @flags:  Computes active flags
 * @width: Specifies the width
 * @precision: Precision specification
 * @size: Specifies the size
 * Return: The amount of chars printed
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int len = 0, i;
	char *x = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (x == NULL)
	{
		x = "(null)";
		if (precision >= 6)
			x = "      ";
	}

	while (x[len] != '\0')
		len++;

	if (precision >= 0 && precision < len)
		len = precision;

	if (width > len)
	{
		if (flags & F_MINUS)
		{
			write(1, &x[0], len);
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			write(1, &x[0], len);
			return (width);
		}
	}

	return (write(1, x, len));
}
/** TO PRINT PERCENT SIGN */
/**
 * print_percent - This is a function that prints a percent sign
 * @types: This is a list of arguments passed to the function
 * @buffer: This is an array to handle print
 * @flags:  Computes active flags
 * @width: Specifies the width
 * @precision: Precision specification
 * @size: Specifies the size
 * Return: The amount of chars printed
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/** TO PRINT INTEGERS */
/**
 * print_int - This is a function that prints integers
 * @types: This is a list of arguments passed to the function
 * @buffer: This is an array to handle print
 * @flags:  Computes active flags
 * @width: Specifies the width
 * @precision: Precision specification
 * @size: Specifies the size
 * Return: The amount of chars printed
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int x = BUFF_SIZE - 2;
	int neg = 0;
	long int y = va_arg(types, long int);
	unsigned long int z;

	y = convert_size_number(y, size);

	if (y == 0)
		buffer[x--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	z = (unsigned long int)y;

	if (y < 0)
	{
		z = (unsigned long int)((-1) * y);
		neg = 1;
	}

	while (z > 0)
	{
		buffer[x--] = (z % 10) + '0';
		z /= 10;
	}

	x++;

	return (write_number(neg, x, buffer, flags, width, precision, size));
}

/** TO PRINT BINARY NUMBERS */
/**
 * print_binary - This is a function that prints an unsigned number
 * @types: This is a list of arguments passed to the function
 * @buffer: This is an array to handle print
 * @flags:  Computes active flags
 * @width: Specifies the width
 * @precision: Precision specification
 * @size: Specifies the size
 * Return: The amount of chars printed
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int x, y, i, total;
	unsigned int a[32];
	int tally;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	x = va_arg(types, unsigned int);
	y = 2147483648;
	a[0] = x / y;
	for (i = 1; i < 32; i++)
	{
		y /= 2;
		a[i] = (x / y) % 2;
	}
	for (i = 0, total = 0, tally = 0; i < 32; i++)
	{
		total += a[i];
		if (total || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			tally++;
		}
	}
	return (tally);
}
