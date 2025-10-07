#include <stdio.h>
#include "card.h"

void printCard(Card c) {
    const char *colors[] = {"Red", "Green", "Blue", "Yellow"};
    printf("[%s %d]", colors[c.color], c.value);
}

int canPlay(Card a, Card b) {
    return (a.color == b.color || a.value == b.value);
}
