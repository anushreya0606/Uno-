# UNO Game Makefile

CC = gcc
CFLAGS = -Wall
OBJS = main.o card.o deck.o player.o game.o

all: uno

uno: $(OBJS)
	$(CC) $(CFLAGS) -o uno $(OBJS)

main.o: main.c game.h
	$(CC) $(CFLAGS) -c main.c

card.o: card.c card.h
	$(CC) $(CFLAGS) -c card.c

deck.o: deck.c deck.h card.h
	$(CC) $(CFLAGS) -c deck.c

player.o: player.c player.h deck.h card.h
	$(CC) $(CFLAGS) -c player.c

game.o: game.c game.h player.h
	$(CC) $(CFLAGS) -c game.c

clean:
	rm -f *.o uno
