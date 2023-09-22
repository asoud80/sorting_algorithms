#include "deck.h"

char get_value(deck_node_t *card);
int _strcmp(const char *s1, const char *s2);
void insertion_sort_deck_kind(deck_node_t **deck);
void sort_deck(deck_node_t **deck);
void insertion_sort_deck_value(deck_node_t **deck);


/**
 * _strcmp - to compares 2 Strings.
 *
 * @s1: 1st String To Be Compared
 *
 * @s2: 2nd String To Be compared.
 * Return: a positive Byte Difference If s1 > s2
 *         0 if s1 == s2
 *         negative Byte Difference If s1 < s2
 */

int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);
	return (0);
}


/**
 * get_value - to get a Numerical Value Of Card
 *
 * @card: the Pointer To Deck_Node_t Card
 * Return: a Numerical Value Of Card.
 */

char get_value(deck_node_t *card)
{
	if (_strcmp(card->card->value, "Ace") == 0)
		return (0);
	if (_strcmp(card->card->value, "1") == 0)
		return (1);
	if (_strcmp(card->card->value, "2") == 0)
		return (2);
	if (_strcmp(card->card->value, "3") == 0)
		return (3);
	if (_strcmp(card->card->value, "4") == 0)
		return (4);
	if (_strcmp(card->card->value, "5") == 0)
		return (5);
	if (_strcmp(card->card->value, "6") == 0)
		return (6);
	if (_strcmp(card->card->value, "7") == 0)
		return (7);
	if (_strcmp(card->card->value, "8") == 0)
		return (8);
	if (_strcmp(card->card->value, "9") == 0)
		return (9);
	if (_strcmp(card->card->value, "10") == 0)
		return (10);
	if (_strcmp(card->card->value, "Jack") == 0)
		return (11);
	if (_strcmp(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}


/**
 * insertion_sort_deck_kind - to Sort Deck Of the Cards From Spades To Diamonds
 *
 * @deck: the Pointer To a head Of Deck_Node_t Doubly_Linked_List
 */

void insertion_sort_deck_kind(deck_node_t **deck)
{
	deck_node_t *iter, *insert, *tmp;

	for (iter = (*deck)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL && insert->card->kind > iter->card->kind)
		{
			insert->next = iter->next;
			if (iter->next != NULL)
				iter->next->prev = insert;
			iter->prev = insert->prev;
			iter->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = iter;
			else
				*deck = iter;
			insert->prev = iter;
			insert = iter->prev;
		}
	}
}
/**
 * insertion_sort_deck_value - to Sort Deck Of Cards Sorted From
 *
 *                             Spades To Diamonds From ace To King
 *
 * @deck: Pointer To a Head Of Deck_Node_t Doubly_Linked_List.
 */

void insertion_sort_deck_value(deck_node_t **deck)
{
	deck_node_t *iter, *insert, *tmp;

	for (iter = (*deck)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL &&
		       insert->card->kind == iter->card->kind &&
		       get_value(insert) > get_value(iter))
		{
			insert->next = iter->next;
			if (iter->next != NULL)
				iter->next->prev = insert;
			iter->prev = insert->prev;
			iter->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = iter;
			else
				*deck = iter;
			insert->prev = iter;
			insert = iter->prev;
		}
	}
}
/**
 * sort_deck - to sort Deck of Cards From ace To king &
 *
 *             From Spades To Diamonds
 *
 * @deck: Pointer To a head Of Deck_Node_t Doubly_Linked_List
 */

void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	insertion_sort_deck_kind(deck);
	insertion_sort_deck_value(deck);
}
