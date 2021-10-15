#include "SingleLinkedList.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    SingleLinkedList<string> *list = new SingleLinkedList<string>();
    SingleLinkedItem<string> a = SingleLinkedItem<string>("end");
    
    list->addFront(a);
    a = SingleLinkedItem<string>("front");
    list->addFront(a);
    a = SingleLinkedItem<string>("popfront");
    list->addFront(a);
    cout<<(*list);
    list->removeFront();
    cout<<(*list);
    list->removeFront();
    cout<<(*list);
    list->removeFront();
    cout<<(*list);
    list->removeFront();
    cout<<(*list);
    list->removeFront();
    cout<<(*list);
    return 0;
}