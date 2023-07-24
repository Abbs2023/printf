#include "main.h"

<<<<<<< HEAD
/****************** PRINT POINTER ******************/
=======
/******* PRINT POINTER FOR MY PROJECT *********/
>>>>>>> dd9ee8209f9a25093a1f388ff3c410222b235076
/**
 * print_pointer - Prints the value of a pointer variable
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_pointer(va_list types, char buffer[],
<<<<<<< HEAD
	int flags, int width, int precision, int size)
=======
		int flags, int width, int precision, int size)
>>>>>>> dd9ee8209f9a25093a1f388ff3c410222b235076
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;

	ind++;
<<<<<<< HEAD

=======
>>>>>>> dd9ee8209f9a25093a1f388ff3c410222b235076
	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (write_pointer(buffer, ind, length,
		width, flags, padd, extra_c, padd_start));
}

<<<<<<< HEAD
/************* PRINT NON PRINTABLE *************/
=======
/************* PRINT NON PRINTABLE FOR ME ***********/
>>>>>>> dd9ee8209f9a25093a1f388ff3c410222b235076
/**
 * print_non_printable - Prints ascii codes in hexa of non printable chars
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
<<<<<<< HEAD
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
=======
 * @flags:  Calculates active flag
 * @width: get widths for me
 * @precision: Precision specifications
 * @size: Size specifiers for peter
 * Return: Number of chars printed for me
 */
int print_non_printable(va_list types, char buffer[],
		int flags, int width, int precision, int size)
>>>>>>> dd9ee8209f9a25093a1f388ff3c410222b235076
{
	int i = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
<<<<<<< HEAD

=======
>>>>>>> dd9ee8209f9a25093a1f388ff3c410222b235076
	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buffer[i + offset] = str[i];
		else
<<<<<<< HEAD
			offset += append_hexa_code(str[i], buffer, i + offset);
=======
			offset +=
				append_hexa_code(str[i], buffer, i + offset);
>>>>>>> dd9ee8209f9a25093a1f388ff3c410222b235076

		i++;
	}

	buffer[i + offset] = '\0';

	return (write(1, buffer, i + offset));
}

<<<<<<< HEAD
/********** PRINT REVERSE FOR ME ***************/
/**
 * print_reverse - Prints reverse string
 * @types: List a of argument
 * @buffer: Buffer array to handle print.
 * @flags:  Calculates active flags FOR ME
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier COOL
 * Return: Numbers of chars printed
 */

=======
/************ PRINT REVERSE FOR OUR PROJECTS********/
/**
 *print_reverse - Prints reverse string to make worl good.
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width for my work
 * @precision: Precision specification
 * @size: Size specifier in this project
 * Return: Numbers of chars printed
 */
>>>>>>> dd9ee8209f9a25093a1f388ff3c410222b235076
int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int i, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
<<<<<<< HEAD
/************* PRINT A STRING IN ROT13 FOR PETER AND ABBY  *************/
/**
 * print_rot13string - Print a string in rot13
 * @types: List a of argument
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags nicely
 * @width: get width for me
 * @precision: Precision specification for me
 * @size: Size specifiers
 * Return: Numbers of chars printed cool
=======

/*************** PRINT A STRING IN ROT13 FOR ME *********/
/**
 * print_rot13string - Print for a string in rot13.
 * @types: List a  of arguments for peter
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get widths
 * @precision: Precision specifications
 * @size: Size specifiers
 * Return: Numbers of chars printed for us
>>>>>>> dd9ee8209f9a25093a1f388ff3c410222b235076
 */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
<<<<<<< HEAD
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
=======
	char in[] =
"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] =
"NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
>>>>>>> dd9ee8209f9a25093a1f388ff3c410222b235076

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
