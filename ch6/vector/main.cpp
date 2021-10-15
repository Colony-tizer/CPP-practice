#include "VectorArr.h"
#include <iostream>
using namespace std;
int main() {
    VectorArr<int> a(3);
    cout<<a.toString();
    a.insertAt(a.getSize(), 1);
    cout<<a.toString();
    a.insertAt(a.getSize(), 2);
    cout<<a.toString();
    a.insertAt(a.getSize(), 3);
    cout<<a.toString();
    a.setAt(0, 10);
    cout<<a.toString();
    a.insertAt(a.getSize(), 13);
    cout<<a.toString();
    cout<<a.getSize()<<endl;
}