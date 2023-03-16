#include <stdlib.h>
#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index index of a
 * dlistint_t linked list
 * @head: pointer to the head of the list
 * @index: index of the node to delete (starting from 0)
 *
 * Return: 1 if it succeeded, -1 if it failed
 **/
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current, *tmp;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	current = *head;

	if (index == 0) /* delete the first node */
		return (-1);

	current = *head;

	if (index == 0) /* delete the first node */
	{
		*head = current->next;
		if (current->next != NULL)
			current->next->prev = NULL;
		free(current);
		return (1);
	}

	/* Traverse the list until the position index */
	for (i = 0; i < index && current != NULL; i++)
		current = current->next;

	if (current == NULL) /* index out of bounds */
		return (-1);

	/* Delete the node */
	tmp = current->prev;
	tmp->next = current->next;
	if (current->next != NULL)
		current->next->prev = tmp;
	free(current);

	return (1);
}
