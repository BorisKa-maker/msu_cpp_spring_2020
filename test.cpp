#include<iostream>
#include "alloc.h"

using namespace std;

int main()
{
	bool test = true;
	makeAllocator(sizeof(int) *8);
	int* i1 = (int*)alloc(sizeof(int)*4);
	int* i2 = (int*)alloc(sizeof(int)*4);
	*i1 = 10;
	*i2 = 20;
	test = ((*i1 + *i2) == 30);
	if (test)
	{
		cout << "Excellent"<<endl;
	}
	else
	{
		cout << "Error in the firts test"<<endl;
	}
	reset();
	makeAllocator(sizeof(char) * 8);
	char* j1 = (char*)alloc(sizeof(char)*4);
	char* j2 = (char*)alloc(sizeof(char) * 4);
	char* j3 = (char*)alloc(sizeof(char));
	if (j3 == nullptr)
	{
		cout << "Excellent" << endl;
	}
	else
	{
		cout << "Error in the second test" << endl;
	}

}