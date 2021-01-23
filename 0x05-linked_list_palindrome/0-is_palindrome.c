#include "lists.h"
#include <stdlib.h>
#include <stdio.h>


/**
 * is_palindrome - Checks if a list is palindrome.
 * @head: Address of head pointer of list.
 *
 * Return: 1 is palindrome, 0 if not.
 */
int is_palindrome(listint_t **head)
{
	listint_t *iterator = NULL;
	int list_arr[9999];
	int size, left, right;

	if (*head == NULL)
		return (1);

	size = 0;
	iterator = *head;
	while (iterator->next)
	{
		list_arr[size] = iterator->n;
		iterator = iterator->next;
		size++;
	}
	list_arr[size] = iterator->n;
	size += 1;

	left = 0;
	right = size - 1;
	while (left < right)
	{
		if (list_arr[left] != list_arr[right])
		{
			return (0);
		}
		left++;
		right--;
	}
	return (1);
}
