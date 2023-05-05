#include "sort.h"

/**
 * swap_node_ahead - Swap a node in a listint_t doubly-linked list
 *                   list of integers with the node ahead of it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @shaker: A pointer to the current swapping node of the cocktail shaker algo.
 */
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker)
{
    listint_t *tmp = (*shaker)->next;

    // Update prev and next pointers to remove current node
    if ((*shaker)->prev != NULL)
        (*shaker)->prev->next = tmp;
    else
        *list = tmp;
    tmp->prev = (*shaker)->prev;

    // Update prev and next pointers to insert current node ahead
    (*shaker)->next = tmp->next;
    if (tmp->next != NULL)
        tmp->next->prev = *shaker;
    else
        *tail = *shaker;
    (*shaker)->prev = tmp;
    tmp->next = *shaker;
    *shaker = tmp;
}

/**
 * swap_node_behind - Swap a node in a listint_t doubly-linked
 * list of integers with the node behind it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @shaker: A pointer to the current swapping node of the cocktail shaker algo.
 */
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker)
{
    listint_t *tmp = (*shaker)->prev;

    // Update prev and next pointers to remove current node
    if ((*shaker)->next != NULL)
        (*shaker)->next->prev = tmp;
    else
        *tail = tmp;
    tmp->next = (*shaker)->next;

    // Update prev and next pointers to insert current node behind
    (*shaker)->prev = tmp->prev;
    if (tmp->prev != NULL)
        tmp->prev->next = *shaker;
    else
        *list = *shaker;
    (*shaker)->next = tmp;
    tmp->prev = *shaker;
    *shaker = tmp;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 *                      ascending order using the cocktail shaker algorithm.
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
    listint_t *tail, *shaker;
    bool shaken_not_stirred = false;

    // Check if list is empty or has only one element
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    // Find tail node
    for (tail = *list; tail->next != NULL;)
        tail = tail->next;

    // Perform cocktail shaker algorithm until no swaps are made
    while (shaken_not_stirred == false)
    {
        shaken_not_stirred = true;

        // Move shaker node from left to right
        for (shaker = *list; shaker != tail; shaker = shaker->next)
        {
            //If the current node's value is greater than the next node's value
			if (shaker->n > shaker->next->n)
			{
				swap_node_ahead(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
		//Loop backward through the list
		for (shaker = shaker->prev; shaker != *list;
				shaker = shaker->prev)
		{
			//If the current node's value is less than the previous node's value
			if (shaker->n < shaker->prev->n)
			{
				swap_node_behind(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
	}
}