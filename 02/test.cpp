#include "name.h"

void Beg() {
    std::cout << "begin"<<endl;
}

void End() {
    std::cout << "end" <<endl;
}

void Numbers(int n) {
    std::cout << n << "- numbers" <<endl;
}

void Letters(const string& n) {
    std::cout << n << "- string"<<endl;
}
int main()
{
    initial_callback(Numbers, Letters, Beg, End);
    cout << "test1:" << endl;
	parser("1456 234   Hello\nWorld\n222 Ptr\t End(");
    cout << "test2:" << endl;
    parser("\n\n\n\t\t\t\n");


}