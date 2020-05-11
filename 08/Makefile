all: pool

vector: test.o
    g++ -o pool test.o

test.o: test.cpp pool.h
    g++ -c test.cpp

run: pool
    ./pool
clean:
    rm -rf*.o pool
