#include "main.h"

/*** PRINTS CHAR FOR THIS TASK ***/

/**
 * print_char - A function that prints a char for the task
 * @types: A function that list a arguments for this task
 * @buffer: Buffer array needed to handle print
 * @flags:  A function that calculates the active flags in this task
 * @width: A function to calculate Width used
 * @precision: Precision specification of the code
 * @size: Size specifier of the code
 * Return: Number of chars to be printed
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
/*** PRINTS A STRING FOR THIS TASK ***/
/**
 * print_string - A function that prints a string for the task
 * @types: A function that list a of arguments for this task
 * @buffer: Buffer array needed to handle print
 * @flags:  A function that calculates the active flags in this task
 * @width: A function that gets width for the task
 * @precision: Precision specification of the code
 * @size: Size specifier of the code
 * Return: Number of chars to be printed
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}
/***** PRINTS A PERCENT SIGN FOR THE TASK ****/
/**
 * print_percent - A function that prints a percent sign
 * @types: A funtion that list a of arguments
 * @buffer: A buffer array needed to handle print
 * @flags:  A function that calculates the active flags
 * @width: A function that gets width
 * @precision: Precision specification of the code
 * @size: Size specifier of the code
 * Return: Number of chars to be printed
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

/***** PRINTS AN INT FOR THIS TASK ***/
/**
 * print_int - A function that prints int
 * @types: A function that list a of arguments
 * @buffer: A buffer array needed to handle print
 * @flags:  A function that calculates active flags
 * @width: A function that gets width
 * @precision: Precision specification of the code
 * @size: A function that specifies size
 * Return: Number of chars to be printed
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}

/*** PRINT BINARY ***/
/**
 * print_binary - A function that prints an unsigned number
 * @types: A function that list a of arguments
 * @buffer: A buffer array needed to handle print
 * @flags:  A function that calculates active flags
 * @width: A function that gets width
 * @precision: Precision specification of the code
 * @size: A function that specifies size
 * Return: Numbers of char to be printed.
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}

