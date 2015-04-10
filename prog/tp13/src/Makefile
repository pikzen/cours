CC=g++-4.9
CFLAGS=-Wall -I../include -g -fdiagnostics-color=always
CLIBS=-L../lib -loutils
LDFLAGS=
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)
EXEC=../build/mix
DEBUGDIR=../debug/

all: objects
	$(CC) $(LDFLAGS) $(OBJ) -o $(EXEC) $(CLIBS)

objects:
	$(CC) $(CFLAGS) -c $(SRC)

debug: prod
	valgrind --leak-check=full $(EXEC)

prop: mrproper all

.PHONY: clean mrproper

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
	rm -rf *~
