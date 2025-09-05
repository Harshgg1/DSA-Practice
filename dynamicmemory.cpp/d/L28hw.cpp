//void pointer and aaddress typecasting
#include <iostream>
using namespace std;

int main() {
    int x = 65;
    void* ptr = &x; // void* = type-less pointer

    // Cast address to int*
    cout << *(int*)ptr << endl;  // 65

    // Cast address to char*
    cout << *(char*)ptr << endl; // 'A' (65 in ASCII)

    return 0;
}
