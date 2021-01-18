#include "lists.h"
#include <stdlib.h>

/**
 * is_palindrome_r - Recursive function to evaluate if an array is palindrome.
 * @array: Array to check.
 * @left: Index to left position in the array.
 * @right: Index to right position in the array.
 * @is_pal: Indicated whether the array could be a palindrome or not.
 *
 */
void is_palindrome_r(int *array, int left, int right, int *is_pal)
{
	if (left < right && *is_pal == 1)
	{
		if (array[left] != array[right])
		{
			is_pal = 0;
		}
		else
		{
			left++;
			right--;
			is_palindrome_r(array, left, right, is_pal);
		}
	}
}

/**
 * is_palindrome - Checks if a list is palindrome.
 * @head: Address of head pointer of list.
 *
 * Return: 1 is palindrome, 0 if not.
 */
int is_palindrome(listint_t **head)
{
	listint_t *iterator = NULL;
	int *list_arr = NULL;
	int size = 0;
	int i = 0;
	int is_pal = 1;

	if (*head == NULL)
		return (1);

	iterator = *head;
	while (iterator->next)
	{
		iterator = iterator->next;
		size++;
	}

	list_arr = (int *)malloc(sizeof(int) * size);

	iterator = *head;
	while (iterator->next)
	{
		list_arr[i] = iterator->n;
		iterator = iterator->next;
		i++;
	}
	is_palindrome_r(list_arr, 0, size - 1, &is_pal);
	return (is_pal);
}
