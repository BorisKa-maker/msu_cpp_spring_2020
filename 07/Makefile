all: vector

vector: test.o
    g++ -o vector test.o

test.o: test.cpp Vector.h
    g++ -c test.cpp

run: vector
    ./vector
clean:
    rm -rf*.o vector
