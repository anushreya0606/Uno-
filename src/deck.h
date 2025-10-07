#ifndef DECK_H
#define DECK_H
#include "card.h"

#define MAX 100

typedef struct {
    Card arr[MAX];
    int front, rear;
} Queue;

typedef struct {
    Card arr[MAX];
    int top;
} Stack;

void initQueue(Queue *q);
void enqueue(Queue *q, Card c);
Card dequeue(Queue *q);
int isEmptyQueue(Queue *q);

void initStack(Stack *s);
void push(Stack *s, Card c);
Card peek(Stack *s);
int isEmptyStack(Stack *s);

void createDeck(Queue *deck);
void shuffleDeck(Queue *deck);

#endif
