#include "SingleLinkedList.h"
#include <iostream>
#include <string>
using namespace std;

const uint8_t REMOVE_TEST_COUNT = 5;

int main() {
    SingleLinkedList<string> *list = new SingleLinkedList<string>();
    SingleLinkedItem<string> addingItem = SingleLinkedItem<string>("end");
    
    list->addFront(addingItem);
    addingItem = SingleLinkedItem<string>("front");
    list->addFront(addingItem);
    addingItem = SingleLinkedItem<string>("popfront");
    list->addFront(addingItem);

    for (auto i = REMOVE_TEST_COUNT; i > 0; --i) {
        cout << (*list) << endl;
        list->removeFront();
    }

    delete list;

    return 0;
}