#include "ListPriorityQueue.h"
#include <iostream>
using namespace std;

struct isIntLess {
    inline bool operator() (int a, int b) { return a < b; }
};

int main() {
    ListPriorityQueue<int, isIntLess> pq;
    pq.insert(0); 
    pq.insert(10); 
    pq.insert(-1);
    while (!pq.isEmpty()) {
        cout<<pq.getMin()<<" ";
        pq.removeMin();
    }
    cout<<endl;
    auto ans = "yes";
    if (!pq.isEmpty()) ans = "no";
    cout<<"is queue empty: "<<ans<<endl;
    try {
        pq.removeMin();
    } catch (QueueEmptyError& ex) {
        cout<<ex.what()<<endl;
    }
}