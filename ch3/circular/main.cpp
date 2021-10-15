#include <iostream>
#include "CList.h"
using namespace std;
template <class T>
void printAllList(CList<T>* list) {
    int total = list->getSize();
    while (total-- > 0) {
        cout<<list->back()<<" ";
        list->advance();
    }
    cout<<endl;
}
int main() {
    CList<int> *cl = new CList<int>();
    cl->add(1);
    cout<<"cur: "<<cl->back()<<endl;
    cout<<"next: "<<cl->front()<<endl;
    printAllList(cl);
    cl->advance();
    printAllList(cl);
    cl->add(10);
    printAllList(cl);
    cl->add(100);
    printAllList(cl);
    try {
        while (cl->getSize() >= 0)
            cl->remove();
    } catch (ListEmptyError& err) {
        cout<<err.what()<<endl;
    }
}