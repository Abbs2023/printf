#include "main.h"

/*** PRINTS AN UNSIGNED NUMBER FOR THIS TASK***/
/**
 * print_unsigned - A function that prints an unsigned number
 * @types: A function that list a of arguments
 * @buffer: A buffer array needed to handle print
 * @flags:  A function that calculates active flags
 * @width: A function that gets width
 * @precision: Precision specification of the code
 * @size: A function that specifies size
 * Return: Number of chars to be printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/*** PRINTS AN UNSIGNED NUMBER IN OCTAL  ***/
/**
 * print_octal - A function that prints an unsigned number in octal notation
 * @types: A function that list a of arguments
 * @buffer: A buffer of array needed to handle print
 * @flags:  A function that calculates active flags
 * @width: A function that gets width
 * @precision: Precision specification of the code
 * @size: A function that specifies size
 * Return: Number of chars to be printed
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/*** PRINTS AN UNSIGNED NUMBER IN HEXADECIMAL FOR THIS TASK***/
/**
 * print_hexadecimal - This prints an unsigned number in hexadecimal notation
 * @types: A function that list a of arguments
 * @buffer: A buffer of array to handle print
 * @flags:  A function that calculates active flags
 * @width: A function that gets width
 * @precision: Precision specification of the code
 * @size: A function that specifies size
 * Return: Number of chars to be printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/*** PRINTS AN UNSIGNED NUMBER IN UPPER HEXADECIMAL ***/
/**
 * print_hexa_upper - It print an unsigned number in upper hexadecimal notation
 * @types: A function that list a of arguments
 * @buffer: A buffer of array to handle print
 * @flags:  A function that calculates active flags
 * @width: A function that gets width
 * @precision: Precision specification of the code
 * @size: A function that specifies size
 * Return: Number of chars to be printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/*** PRINTS HEXX NUMBER IN LOWER OR UPPER ***/
/**
 * print_hexa - A function that prints a hexadecimal number in lower or upper
 * @types: A function that list a of arguments
 * @map_to: An array of values to set the number to
 * @buffer: A buffer of array to handle print
 * @flags:  A function that calculates active flags
 * @flag_ch: A function that calculates active flags for this code
 * @width: A function that gets width
 * @precision: Precision specification of the code
 * @size: A function that specifies size
 * @size: Specification of the size
 * Return: Number of chars to be printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
