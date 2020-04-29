
all: big

big: BigInt.o test.o
		g++ - o big BigInt.o test.o

BigInt.o : BigInt.cpp BigInt.h
	g++ - c BigInt.cpp

test.o : test.cpp BigInt.h
	g++ - c test.cpp

clean :
	rm - rf * .o big
