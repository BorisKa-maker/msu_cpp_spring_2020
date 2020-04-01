all: pars

pars : parser.o test.o
	g++ -o pars parser.o test.o

parser.o : parser.cpp name.h
	g++ -c parser.cpp

test.o : test.cpp name.h
	g++ -c test.cpp

clean :
	rm - rf *.o pars
