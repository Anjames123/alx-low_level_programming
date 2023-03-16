#include <stdlib.h>
#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position.
 * @h: pointer to the head of the doubly linked list
 * @idx: index of the list where the new node should be added.
 *Index starts at 0
 * @n: value of the new node
 *
 * Return: the address of the new node, or NULL if it failed
 **/
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node, *tmp = *h;
	unsigned int i;

	if (h == NULL || idx == 0)
		return (add_dnodeint(h, n)); /* add node at the beginning */

	/* Traverse the list until the position idx-1 */
	for (i = 0; i < idx - 1 && tmp != NULL; i++)
		tmp = tmp->next;

	if (tmp == NULL) /* index out of bounds */
		return (NULL);

	/* Create the new node */
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->prev = tmp;
	new_node->next = tmp->next;

	if (tmp->next != NULL)
		tmp->next->prev = new_node;

	tmp->next = new_node;

	return (new_node);
}
