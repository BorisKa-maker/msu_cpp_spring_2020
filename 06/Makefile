all: format

format: test.o
    g++ -o format test.o

test.o: test.cpp format.h
    g++ -c test.cpp

run: format
    ./format
clean:
    rm -rf*.o format
