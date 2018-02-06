CC=g++ 
CFLAGS=-Wall -std=c++11 -ggdb
LDFLAGS=

all: over_op

over_op: main.o Data.o
	$(CC) main.o Data.o -o  over_op $(LDFLAGS)
	
main.o: main.cpp Data.hpp
	$(CC) $(CFLAGS) -c main.cpp -o main.o $(LDFLAGS)

Data.o: Data.cpp Data.hpp
	$(CC) $(CFLAGS) -c Data.cpp -o Data.o $(LDFLAGS)
	
clean:
	rm -f  *.o over_op
