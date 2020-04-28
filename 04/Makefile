all: serializ

serializ: Serializer.o test.o
		g++ - o serializ Serializer.o test.o

Serializer.o : Serializer.cpp Serializer.h
	g++ - c Serializer.cpp

test.o : test.cpp Serializer.h
	g++ - c test.cpp

clean :
	rm - rf * .o serializ
