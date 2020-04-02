all: matrix

matrix : Matrix.o test.o
		g++ - o matrix Matrix.o test.o

Matrix.o : Matrix.cpp Matrix.h
	g++ - c Matrix.cpp

test.o : test.cpp Matrix.h
	g++ - c test.cpp

clean :
	rm - rf * .o matrix
