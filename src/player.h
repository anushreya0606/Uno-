#ifndef PLAYER_H
#define PLAYER_H
#include "card.h"
#include "deck.h"

typedef struct Node {
    Card data;
    struct Node *next;
} Node;

void addCard(Node **head, Card c);
void removeCard(Node **head, int index);
int listSize(Node *head);
Card getCard(Node *head, int index);
void showHand(Node *head);
int playTurn(Node **hand, Stack *discard, Queue *deck);

#endif
