#include <stdio.h>
#include <stdlib.h>
#include "player.h"

void addCard(Node **head, Card c) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = c;
    newNode->next = *head;
    *head = newNode;
}

void removeCard(Node **head, int index) {
    Node *temp = *head, *prev = NULL;
    if (index == 0 && temp) {
        *head = temp->next;
        free(temp);
        return;
    }
    for (int i = 0; temp && i < index; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

int listSize(Node *head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

Card getCard(Node *head, int index) {
    for (int i = 0; i < index && head; i++) head = head->next;
    return head->data;
}

void showHand(Node *head) {
    int i = 1;
    while (head) {
        printf("%d:", i++);
        printCard(head->data);
        printf("  ");
        head = head->next;
    }
    printf("\n");
}

int playTurn(Node **hand, Stack *discard, Queue *deck) {
    Card top = peek(discard);
    int size = listSize(*hand);

    printf("Your hand: ");
    showHand(*hand);
    printf("Top Card: ");
    printCard(top);
    printf("\n");

    // Check for playable cards
    int hasPlayable = 0;
    for (int i = 0; i < size; i++) {
        if (canPlay(getCard(*hand, i), top)) {
            hasPlayable = 1;
        }
    }

    if (!hasPlayable) {
        printf("No match, drawing card...\n");
        if (!isEmptyQueue(deck)) addCard(hand, dequeue(deck));
        return 0;
    } else {
        int choice;
        do {
            printf("Enter card number to play (1-%d): ", size);
            scanf("%d", &choice);
        } while (choice < 1 || choice > size || !canPlay(getCard(*hand, choice - 1), top));

        Card played = getCard(*hand, choice - 1);
        push(discard, played);
        removeCard(hand, choice - 1);
        printf("Played ");
        printCard(played);
        printf("\n");
        return 1;
    }
}
