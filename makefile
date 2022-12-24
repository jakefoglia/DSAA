CC=g++
CFLAGS= -o2 -Wall -Wextra -Werror -pedantic --std=c++2a

dijkstras: src/dijkstras.cc
	$(CC) $(CFLAGS) src/dijkstras.cc -o bin/dijkstras.exe

	
sorts: src/sorts.cc
	$(CC) $(CFLAGS) src/sorts.cc -o bin/sorts.exe

all: dijkstras sorts
