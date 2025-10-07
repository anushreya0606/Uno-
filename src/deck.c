#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "deck.h"

void initQueue(Queue *q) { q->front = q->rear = -1; }

int isEmptyQueue(Queue *q) { return q->front == -1; }

void enqueue(Queue *q, Card c) {
    if (q->rear == MAX - 1) return;
    if (q->front == -1) q->front = 0;
    q->arr[++q->rear] = c;
}

Card dequeue(Queue *q) {
    Card c = {-1, -1};
    if (isEmptyQueue(q)) return c;
    c = q->arr[q->front];
    if (q->front == q->rear) q->front = q->rear = -1;
    else q->front++;
    return c;
}

void initStack(Stack *s) { s->top = -1; }
int isEmptyStack(Stack *s) { return s->top == -1; }

void push(Stack *s, Card c) {
    if (s->top < MAX - 1) s->arr[++s->top] = c;
}

Card peek(Stack *s) {
    if (s->top >= 0) return s->arr[s->top];
    Card c = {-1, -1};
    return c;
}

void createDeck(Queue *deck) {
    Card temp;
    for (int color = 0; color < COLORS; color++) {
        for (int value = 0; value < VALUES; value++) {
            temp.color = color;
            temp.value = value;
            enqueue(deck, temp);
        }
    }
}

void shuffleDeck(Queue *deck) {
    int n = deck->rear + 1;
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        int r = rand() % n;
        Card t = deck->arr[i];
        deck->arr[i] = deck->arr[r];
        deck->arr[r] = t;
    }
}
