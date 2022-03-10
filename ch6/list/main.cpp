#include "NodeList.h"
#include <iostream>
using namespace std;

template <typename T>
void printList(const NodeList<T>& list) {
    for (auto el : list) {
        cout<<el<<" <-> ";
    }
    cout<<"NULL\n";
}

void demoListInsertIterateRemove() {
    NodeList<int> nodeList;
    nodeList.insertFront(1);
    nodeList.insertFront(2);
    nodeList.insertFront(3);

    for (auto it = nodeList.begin(); it != nodeList.end(); ++it)
        nodeList.remove(it);
}

void createListWithOddLeftEvenRight() {
    const int MAX_INSERTIONS = 9;
    
    NodeList<int> nodeList;

    for (auto i = 0; i < MAX_INSERTIONS; ++i) {
        if (i % 2 == 0) 
            nodeList.insertBack(i);
        else 
            nodeList.insertFront(i);
    }

    printList(nodeList);
}

int main() {
    demoListInsertIterateRemove();
    createListWithOddLeftEvenRight();
}