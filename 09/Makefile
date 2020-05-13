all: sort

vector: test.o
    g++ -o sort test.o

test.o: test.cpp sort.h
    g++ -c test.cpp

run: sort
    ./sort
clean:
    rm -rf*.o sort
