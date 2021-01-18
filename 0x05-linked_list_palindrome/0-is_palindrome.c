#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * is_palindrome_r - Recursive function to evaluate if an array is palindrome.
 * @array: Array to check.
 * @left: Index to left position in the array.
 * @right: Index to right position in the array.
 *
 * Return: 1 if it's palindrome and 0 if it's not.
 */
int is_palindrome_rec(int *array, int left, int right)
{
	if (left >= right)
	{
		return (1);
	}
	else if (array[left] == array[right])
	{
		return is_palindrome_rec(array, left + 1, right - 1);
	}
	else
	{
		return (0);
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

	if (*head == NULL)
		return (1);

	iterator = *head;
	while (iterator->next)
	{
		iterator = iterator->next;
		size++;
	}
	size += 1;

	list_arr = (int *)malloc(sizeof(int) * size);

	iterator = *head;
	while (iterator->next)
	{
		list_arr[i] = iterator->n;
		iterator = iterator->next;
		i++;
	}
	list_arr[i] = iterator->n;

	return is_palindrome_rec(list_arr, 0, size - 1);
}
