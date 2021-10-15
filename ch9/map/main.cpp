#include "Map.h"
#include "iostream"
using namespace std;
int main() {
    Map<int,int> a;
    a.put(1, 1);
    a.put(1, 10);
    cout<<(*(a.find(1))).value()<<endl;
    cout<<a.getSize()<<endl;
    a.put(2, 15);
    a.erase(1);
    cout<<(*(a.find(2))).value()<<endl;
    cout<<a.getSize()<<endl;
    auto pos = a.find(2);
    a.erase(pos);
    cout<<a.getSize()<<endl;
}