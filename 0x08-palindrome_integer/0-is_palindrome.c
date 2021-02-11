#include "palindrome.h"


/**
 * is_palindrome - Checks if a number is palindrome.
 * @n: integer
 *
 * Return: 1 if palindrome or 0 if not..
 */
int is_palindrome(unsigned long n)
{
	int reversed = 0;
	int number = n;
	int remainder = 0;

	while (number)   /*Calculates the reversed number.*/
	{
		remainder = number % 10;
		reversed = reversed * 10 + remainder;
		number /= 10;
	}

	if (n == reversed)
		return (1);
	else
		return (0);
}
