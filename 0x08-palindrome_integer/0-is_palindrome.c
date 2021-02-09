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
	int original = n;
	int remainder = 0;

	while (n)   /*Calculates the reversed. It Will iterate for the length.*/
	{
		remainder = n % 10;
		reversed = reversed * 10 + remainder;
		n /= 10;
	}

	if (original == reversed)
		return (1);
	else
		return (0);
}