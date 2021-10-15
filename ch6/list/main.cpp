#include "NodeList.h"
#include <iostream>
using namespace std;
template <class T>
void printList(const NodeList<T>& list) {
    for (auto it = list.begin(); it != list.end(); 
    it++) {
        cout<<*it<<" <-> ";
    }
    cout<<"NULL\n";
}
int main() {
    NodeList<int> a;
    a.insertFront(1);
    a.insertFront(2);
    a.insertFront(3);
    printList(a);

    for (auto it = a.begin(); it != a.end(); 
    ++it) {
        a.remove(it);
    }
    int max = 5;
    for (int i = 0; i < max; ++i) {
        if (i % 2 == 0) a.insertBack(i);
        else a.insertFront(i);
    }
    printList(a);
}