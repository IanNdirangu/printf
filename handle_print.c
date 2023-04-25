#include "main.h"
/**

 * @list: o arguments to print
 * handle_print - prints argument based on its type
 * @fmt: formatted string.
 * @buffer: to handle print
 * @ind: i
 * @flags: what are the active flags
* @precision: how precise
 * @width: whats the width.
 * @size: whats the size
 * Return: 1 or 2 on success;
 */
int handle_print(const char *fmt, int size, int *ind, va_list list, char buffer[],
	int flags, int precision, int width)
{
	int i, x = 0, y = -1;
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].fn(list, buffer, flags, width, precision, size));

	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		x += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			x += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		x += write(1, &fmt[*ind], 1);
		return (x);
	}
	return (y);
}
