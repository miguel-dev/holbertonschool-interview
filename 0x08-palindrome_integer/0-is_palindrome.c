#include "palindrome.h"

/**
 * reversed - Calculates the reverse number
 * @n: integer
 *
 * Return: Reversed number.
 */
unsigned long reversed(unsigned long n)
{
	unsigned long r = 0;
	unsigned long remainder;

	while (n)   /*Calculates the reversed number.*/
	{
		remainder = n % 10;
		r = r * 10 + remainder;
		n /= 10;
	}
	return (r);
}

/**
 * is_palindrome - Checks if a number is palindrome.
 * @n: integer
 *
 * Return: 1 if palindrome or 0 if not..
 */
int is_palindrome(unsigned long n)
{
	unsigned long r = reversed(n);

	if (n == r)
		return (1);
	else
		return (0);
}
