#include <iostream>
#include <cstdlib>
#include "alloc.h"

size_t OverSize = 0;
size_t keep=0;
char* ptr = nullptr;

using namespace std;

void makeAllocator(size_t maxSize)
{
	if (maxSize)
	{
		OverSize = maxSize;
		keep = 0;
		ptr = (char*)malloc(sizeof(char) * maxSize);
		return;
	}
	else
	{
		return;
	}

}

char* alloc(size_t size)
{
	size_t Keep = keep + size;
	if (ptr && (Keep <= OverSize)) {
		char* p = ptr + keep;
		keep = Keep;
		return p;
	}
	else
	{
		return nullptr;
	}
}

void reset()
{
	OverSize = 0;
	keep = 0;
	free(ptr);
	ptr = nullptr;
	return;
}
