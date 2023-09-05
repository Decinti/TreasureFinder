# Variables
CC = gcc
CFLAGS = -Wall -Wextra -g
OBJS = Bomba.o Tablero.o TreasureFinder.o
EXEC = TreasureFinder
VALGRIND = valgrind --leak-check=full

# Reglas
all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

Bomba.o: Bomba.c Bomba.h Tierra.h
	$(CC) $(CFLAGS) -c Bomba.c

Tablero.o: Tablero.c Tablero.h Bomba.h Tierra.h
	$(CC) $(CFLAGS) -c Tablero.c

TreasureFinder.o: TreasureFinder.c Tablero.h Bomba.h Tierra.h
	$(CC) $(CFLAGS) -c TreasureFinder.c

memcheck: $(EXEC)
	$(VALGRIND) ./$(EXEC)

clean:
	rm -f $(OBJS) $(EXEC)
