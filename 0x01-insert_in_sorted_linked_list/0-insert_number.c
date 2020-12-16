#include "lists.h"
/**
 * insert_node - Inserts a number in a sorted linked list.
 * @head: Pointer to first node of list.
 * @number: Number to be inserted in list.
 *
 * Return: Address of new node or NULL if it failed.
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *newNode; 
	listint_t *temp;
	listint_t *iterator;

	newNode = malloc(sizeof(listint_t));
	if (newNode == NULL)
	{
		return (NULL);
	}

	newNode->n = number;
	newNode->next = NULL;

	if (*head == NULL)
	{
		*head = newNode;
	}
	else if (number < (*head)->n)
	{
		temp = *head;
		*head = newNode;
		newNode->next = temp;
	}
	else
	{
		iterator = *head;
		while (iterator->next != NULL)
		{
			if (number > iterator->n && number < iterator->next->n)
			{
				temp = iterator->next;
				iterator->next = newNode;
				newNode->next = temp;

			}
			iterator = iterator->next;
		}
		if (number > iterator->n)
		{
			iterator->next = newNode;
		}
	}
	return (newNode);
}
