#include "DList.h"
#include <string>
#include <iostream>

using namespace std;
int main() {
    DItem<string> addingItem("goodEnding");
    DList<string> *list = new DList<string>();

    list->getSize();
    list->addFront(addingItem);
    list->addFront("niceContinuation");

    DItem<string> *secondItem = new DItem<string>("unexpectedTurnaround");
    list->addFront(*secondItem);
    list->addFront("awesomeStart");
    int mid = (list->getSize() - 1) / 2 ;

    auto *midItem = new DItem<string>(list->at(mid));
    midItem->print(cout);
    list->addAt(mid, "ordinaryMove");

    addingItem.setValue("boringStart...");
    list->addFront(addingItem);
    addingItem.print(cout)<<endl;
    cout<<(*list);
    
    mid = (list->getSize() - 1) / 2 ;
    list->removeAt(mid);
    cout<<(*list);

    delete secondItem;
    delete list;
    delete midItem;
}