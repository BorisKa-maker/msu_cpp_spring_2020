all: proj

proj: sort.o test.o
    g++ -o sort sort.o test.o

sort.o: sort.cpp sort.h
    g++ -c sort.cpp

test.o: test.cpp sort.h
    g++ -c test.cpp

run: proj
    ./proj
clean:
    rm -rf *.o proj
	rm -rf *.stackdump proj
	rm -rf *.exe proj
