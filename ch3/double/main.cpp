#include "DList.h"
#include <string>
#include <iostream>

using namespace std;
int main() {
    DItem<string> a("goodEnding");
    DList<string> *list = new DList<string>();
    list->getSize();
    list->addFront(a);
    list->addFront("niceContinuation");

    DItem<string> *b = new DItem<string>("unexpectedTurnaround");
    list->addFront(*b);
    list->addFront("awesomeStart");
    int mid = (list->getSize() - 1) / 2 ;

    auto *midItem = new DItem<string>(list->at(mid));
    midItem->print(cout);
    list->addAt(mid, "ordinaryMove");

    a.setValue("boringStart...");
    list->addFront(a);
    a.print(cout)<<endl;
    cout<<(*list);
    
    mid = (list->getSize() - 1) / 2 ;
    list->removeAt(mid);
    cout<<(*list);

    delete b;
    delete list;
    delete midItem;
}