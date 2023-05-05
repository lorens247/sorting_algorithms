#include "sort.h"

/**
 * swap - sorts a doubly linked list of integers in ascending order
 * using the Insertion sort algorithm
 * @a: address of first node
 * @b: address of second node
 *
 * Return: void
 */
void swap(listint_t *a, listint_t *b)
{
    /* Update the next and previous pointers of a and b's neighbors */
	if (a->prev)
		a->prev->next = b;
	if (b->next)
		b->next->prev = a;

    /* Swap the next and previous pointers of a and b */
	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;
}

/**
 * insertion_sort_list - insertion sorts a doubly-linked list
 * @list: address of pointer to head node
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i, *j;

    /* Check if the list exists and has at least 2 nodes */
	if (!list || !*list || !(*list)->next)
		return;

    /* Iterate over the list */
	i = (*list)->next;
	while (i)
	{
		j = i;
		i = i->next;
	/* Move the node at j to its correct position */
	while (j && j->prev)
		{
	/* If the previous node is greater than the current node, swap them */
		if (j->prev->n > j->n)
			{
			swap(j->prev, j);
		/* Update the head of the list if necessary */
		if (!j->prev)
			*list = j;

		/* Print the list after each swap */
	       print_list((const listint_t *)*list);
			}
		else
			j = j->prev;
		}
	}
}

