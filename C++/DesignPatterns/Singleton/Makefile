CC=g++ 
CFLAGS=-Wall -std=c++11 -ggdb
LDFLAGS=

all: singleton

singleton: main.o Singleton.o
	$(CC) main.o Singleton.o -o  singleton $(LDFLAGS)
	
main.o: main.cpp Singleton.hpp
	$(CC) $(CFLAGS) -c main.cpp -o main.o $(LDFLAGS)

Singleton.o: Singleton.cpp Singleton.hpp
	$(CC) $(CFLAGS) -c Singleton.cpp -o Singleton.o $(LDFLAGS)
	
clean:
	rm -f  *.o singleton
