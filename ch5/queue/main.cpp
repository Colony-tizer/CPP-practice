#include "Queue.h"
#include "QueueCL.h"
#include "QueueD.h"
#include <iostream>
#include <vector>
using namespace std;
template <class T>
void fillArr(T* arr, const int size, const int modifier = 1) {
    for (int i = 0; i < size; ++i)
        arr[i] = (i + 1) * modifier;
}
template <class T>
void printArr(T* arr, const int size) {
    for (int i = 0; i < size; ++i) {
        if (i != 0) cout<<", ";
        cout<<arr[i];
    }
    cout<<endl;
}


int main() {
    Queue<int*> *q = new Queue<int*>(10);

    try {
        q->front();
    } catch (QueueEmptyError& ex) {
        cout<<"Cannot get front:"<<endl;
        cout<<ex.what()<<endl;
    }

    int max_size = 10;

    int *arr = new int[max_size];
    fillArr(arr, max_size);

    q->enqueue(arr);

    int *front = q->front();
    printArr(front, max_size);

    q->dequeue();
    try {
        q->dequeue();
    } catch (QueueEmptyError& ex) {
        cout<<"Cannot dequeue:"<<endl;
        cout<<ex.what()<<endl;
    }

    delete q;
    delete front;

    auto *qcl = new QueueCL<string>();
    qcl->enqueue("first!");
    qcl->enqueue("second...");
    cout<<qcl->toString();
    /*for (int i = max_size; i > 0; --i) 
        qcl->enqueue(to_string(i));
    cout<<qcl->toString();*/
    
    while (!qcl->isEmpty()) {
        qcl->dequeue();
        cout<<qcl->toString();
    }

    delete qcl;

    auto *qdl = new QueueD<string>();
    qdl->insertFront("oi");
    cout<<qdl->toString();
    qdl->insertFront("ai");
    qdl->insertBack("i'm back");
    cout<<qdl->toString();
    
    cout<<qdl->front()<<endl;
    cout<<qdl->back()<<endl;
    delete qdl;
}
