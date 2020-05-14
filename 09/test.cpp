#include "sort.h"
#include <ctime>
#include <iostream>
#include <fstream>
#include <cassert>
#include "sort.h"

using namespace std;

int main()
{
    size_t Size = 10000000;
    ofstream ofile;
    uint64_t t;
    uint64_t t1;
    ifstream file;
    ofile.open("bin.dat", ios::binary);
    if (!ofile.is_open())
    {
        cout << "Error open file\n";
        return 0;
    }

    for (uint64_t i = 0; i < Size; i++)
    {
        uint64_t r = rand();
        ofile.write((char*)&r, sizeof(uint64_t));
    }
    ofile.close();

    try
    {
        mysort("bin.dat", "out.dat");

        file.open("out.dat", ios::binary);
        for (uint64_t i = 0; i < Size/2; ++i)
        {
            file.read((char*)&t, sizeof(uint64_t));
            file.read((char*)&t1, sizeof(uint64_t));
            //cout << t << ' ' << t1 << endl;
            assert(t <= t1);
        }
        file.close();
        cout << "Ok\n";
    }
    catch (const exception& err)
    {
        cout << err.what();
    }
    catch (...)
    {
        cout << "Error\n";
    }

    std::remove("bin.dat");
    std::remove("out.dat");
    std::remove("tmp.bin");
}
