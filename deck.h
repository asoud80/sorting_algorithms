#ifndef DECK_H
#define DECK_H

#include <stdlib.h>
/**
 * enum kind_e - to enumerate Card suits
 *
 * @SPADE: to spades Suit
 *
 * @HEART: the hearts Suit
 *
 * @CLUB: the club Suits
 *
 * @DIAMOND: the diamond Suits
 */

typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;


/**
 * struct card_s - to play Cards
 * @value: the value of Cards.
 *
 * from "Ace" To "King".
 *
 * @kind: a kind Of Cards
 */

typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;


/**
 * struct deck_node_s - deck Of Card
 * @card: a pointer To Card Of a Node.
 *
 * @prev: a Pointer To Previous Node Of a List.
 *
 * @next: a Pointer To Next Node Of a List
 */

typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);

#endif
