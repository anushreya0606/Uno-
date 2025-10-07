# === Makefile for UNO Game ===

CC = gcc
CFLAGS = -Wall -g
TARGET = uno

OBJS = main.o game.o player.o deck.o card.o

# Default build rule
$(TARGET): $(OBJS)
	@echo "[LINK] Building executable..."
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
	@echo "✅ Build complete: ./$(TARGET)"

# Individual compilation rules
main.o: main.c game.h
	@echo "[BUILD] main.c"
	$(CC) $(CFLAGS) -c main.c

game.o: game.c game.h player.h deck.h card.h
	@echo "[BUILD] game.c"
	$(CC) $(CFLAGS) -c game.c

player.o: player.c player.h deck.h card.h
	@echo "[BUILD] player.c"
	$(CC) $(CFLAGS) -c player.c

deck.o: deck.c deck.h card.h
	@echo "[BUILD] deck.c"
	$(CC) $(CFLAGS) -c deck.c

card.o: card.c card.h
	@echo "[BUILD] card.c"
	$(CC) $(CFLAGS) -c card.c

# Clean up
clean:
	rm -f *.o $(TARGET)
