#include "lists.h"

/**
 * check_cycle - Checks if a singly linked list has a cycle.
 * @list: Single linked list.
 *
 * Return: 1 if there is a cycle, or 0 otherwise.
 */
int check_cycle(listint_t *list)
{
	listint_t *hare, *tortoise;

	if (!list || !list->next)
		return (0);

	tortoise = list;
	hare = list;

	while (hare)
	{
		tortoise = tortoise->next;

		if (hare->next == NULL)
			break;

		hare = hare->next->next;

		if (tortoise == hare)
			return (1);
	}
	return (0);
}
