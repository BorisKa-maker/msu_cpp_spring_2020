#include "name.h"

void Beg() {
    std::cout << "begin"<<std::endl;
}

void End() {
    std::cout << "end" <<std::endl;
}

void Numbers(int n) {
    std::cout << n << "- numbers" <<std::endl;
}

void Letters(const std::string& n) {
    std::cout << n << "- string"<<std::endl;
}


int main()
{

    initial_callback(Numbers, Letters, Beg, End);
    std::cout << "test1:" << std::endl;
	parser("1456 234   Hello\nWorld\n222 Ptr\t End(");
    initial_callback();
    std::cout << "test2:" << std::endl;
    parser("\n\n\n\t\t\t\n");
    std::cout << "test3:" << std::endl;
    parser("1456 234   Hello\nWorld\n222 Ptr\t End(");


}