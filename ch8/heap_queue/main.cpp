#include "HeapQueue.h"
#include "HeapInPlace.h"
#include "iostream"
using namespace std;

struct isLessInt {
    bool operator()(int a, int b) { return a < b; }
};
struct isGreaterInt {
    bool operator()(int a, int b) { return a > b; }
};
void testHeap() {
    HeapQueue<int, isLessInt> hq;
    hq.insert(0);
    hq.insert(1);
    cout<<"min: "<<hq.getMin()<<endl;
    hq.insert(-1);
    hq.insert(-2);
    hq.insert(2);
    cout<<hq.toString()<<endl;
    cout<<"queue: "<<endl;
    while (!hq.isEmpty()) {
        cout<<hq.getMin()<<endl;
        hq.removeMin();
    }
}
void testHeapInPlace() {
    /*HeapInPlace<int, isGreaterInt> hp;
    hp.add(3);
    hp.add(7);
    hp.add(2);
    hp.add(1);
    hp.add(4);*/
    /*hp.add(9);
    hp.add(25);
    hp.add(5);
    hp.add(16);
    hp.add(15);
    cout<<hp.toString()<<endl;
    hp.sort();
    cout<<hp.toString()<<endl;*/
    HeapInPlace<int, isLessInt> hp1;
    hp1.add(1);
    hp1.add(2);
    hp1.add(3);
    hp1.add(4);
    hp1.add(5);
    hp1.add(6);
    hp1.add(7);
    //hp1.add(4);
    //hp1.add(12);
    cout<<hp1.toString()<<endl;
    hp1.sort();
    cout<<hp1.toString()<<endl;
}
int main() {
    testHeap();
    testHeapInPlace();
}