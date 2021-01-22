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
	int *list_arr = NULL;
	int size, i, left, right;

	if (*head == NULL)
		return (1);

	size = 0;
	iterator = *head;
	while (iterator->next)
	{
		iterator = iterator->next;
		size++;
	}
	size += 1;

	list_arr = (int *)malloc(sizeof(int) * size);

	i = 0;
	iterator = *head;
	while (iterator->next)
	{
		list_arr[i] = iterator->n;
		iterator = iterator->next;
		i++;
	}
	list_arr[i] = iterator->n;

	left = 0;
	right = size - 1;
	while (left < right)
	{
		if (list_arr[left] != list_arr[right])
		{
			free(list_arr);
			return (0);
		}
		left++;
		right--;
	}
	free(list_arr);
	return (1);
}
