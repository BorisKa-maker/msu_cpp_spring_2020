all: allocate

allocate : allocator.o test.o
		g++ - o allocate allocator.o test.o

allocator.o : allocator.cpp alloc.h
g++ - c allocator.cpp

test.o : test.cpp alloc.h
g++ - c test.cpp

clean :
rm - rf * .o allocate