#include <iostream>
#include <limits>
using namespace std;
void printHex(int num) {
    for (size_t ind = 0; ind < sizeof(int); ++ind) {
        
    }
}
int main() {
    int a = 1;
    cout<<numeric_limits<int>::digits<<endl;
    a <<= 27;
    cout<<a<<endl;
    a = (a << 5) | (a >> 27);
    cout<<a<<endl;
}