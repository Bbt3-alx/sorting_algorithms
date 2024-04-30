#include "sort.h"
/**
 * helper - check the nimer
 * @n: The number to be checked.
 * Return: n or -1 on faillir.
 */

ssize_t helper(int n)
{
	int digit;
	char digit_char;
	ssize_t total_bytes_written = 0;

	digit = n % 10;
	if (n == 0)
	{
		return (total_bytes_written);
	}

	if (digit < 0)
		digit = -digit;

	total_bytes_written += helper(n / 10);
	digit_char = digit + '0';
	total_bytes_written += write(STDOUT_FILENO, &digit_char, 1);
	return (total_bytes_written);
}
/**
 * print_int - print the digit wiht it sign.
 * @n: The number to be printed.
 * Return: Nothing
 */
ssize_t print_int(int n)
{
	if (n >= 0)
		return (helper(n));

	write(1, "-", 1);
	return (helper(n) + 1);

}
