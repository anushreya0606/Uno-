#ifndef CARD_H
#define CARD_H

#define COLORS 4
#define VALUES 10

typedef struct {
    int color;   // 0=Red, 1=Green, 2=Blue, 3=Yellow
    int value;   // 0–9
} Card;

void printCard(Card c);
int canPlay(Card a, Card b);

#endif
