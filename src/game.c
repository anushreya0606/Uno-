#include <stdio.h>
#include "game.h"

void startGame() {
    Queue deck;
    Stack discard;
    Node *p1 = NULL, *p2 = NULL;
    int turn = 1;

    initQueue(&deck);
    initStack(&discard);

    createDeck(&deck);
    shuffleDeck(&deck);

    // Deal cards
    for (int i = 0; i < 5; i++) {
        addCard(&p1, dequeue(&deck));
        addCard(&p2, dequeue(&deck));
    }

    // Starting discard card
    push(&discard, dequeue(&deck));

    printf("\n=== UNO (2-Player, DS Modular Version) ===\n");

    while (1) {
        printf("\n-----------------------------------\n");
        if (turn == 1) {
            printf("\nPlayer 1 Turn\n");
            playTurn(&p1, &discard, &deck);
            if (listSize(p1) == 0) {
                printf("\n🎉 Player 1 Wins! 🎉\n");
                break;
            }
            turn = 2;
        } else {
            printf("\nPlayer 2 Turn\n");
            playTurn(&p2, &discard, &deck);
            if (listSize(p2) == 0) {
                printf("\n🎉 Player 2 Wins! 🎉\n");
                break;
            }
            turn = 1;
        }

        if (isEmptyQueue(&deck)) {
            printf("\nDeck Empty! Game Draw.\n");
            break;
        }
    }
}
