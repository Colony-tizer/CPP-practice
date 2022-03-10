#include <iostream>
#include "CList.h"

using namespace std;

template <typename T>
void printAllList(CList<T>* list) {
    int total = list->getSize();
    while (total-- > 0) {
        cout << list->back() << " ";
        list->advance();
    }
    cout << endl;
}

int main() {
    CList<int> *circularList = new CList<int>();
    
    circularList->add(1);
    cout << "cur: " << circularList->back() << endl;
    cout << "next: " << circularList->front() << endl;

    printAllList(circularList);
    circularList->advance();
    printAllList(circularList);
    circularList->add(10);
    printAllList(circularList);
    circularList->add(100);
    printAllList(circularList);

    cout << circularList->toString();

    try {
        while (circularList->getSize() >= 0)
            circularList->remove();
    } catch (ListEmptyError& err) {
        cout << err.what() << endl;
    }
}