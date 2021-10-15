#include <iostream>
#include <vector>
#include "Stack.h"
#include "StackSList.h"
using namespace std;
template <class T>
void fillStack(AStack<T> &stack, const int size) {
    for (int i = 1; i <= size; ++i) {
        stack.push(i);
    }
}
template <class T>
void reverseVec(vector<T> &vec) {
    const int size = vec.size();
    Stack<T> *stack = new Stack<T>(size);
    for (int i = 0; i < size; ++i)
        stack->push(vec.at(i));
    for (int i = 0; i < size; ++i) {
        vec[i] = stack->top();
        stack->pop();
    }
    delete stack;
}
template <class T>
void printVec(vector<T> &vec) {
    for (int i = 0; i < vec.size(); ++i)
        cout<<vec.at(i)<<" ";
    cout<<endl;
}

int main() {
    int max_size = 10;
    auto *s = new Stack<int>(max_size);
    fillStack(*s, max_size);
    cout<<s->top()<<endl;
    try {
        s->push(11); // expected error
    } catch(StackFullException &e) {
        cout<<e.what()<<endl;
    }
    delete s;

    max_size = 3;
    auto *s1 = new Stack<float>(max_size);
    try {
        cout<<s1->top(); // expected error
    } catch(StackEmptyException &e) {
        cout<<e.what()<<endl;
    }
    fillStack(*s1, max_size);
    delete s1;

    auto *s2 = new StackSList<double>();
    fillStack(*s2, 100);
    s2->print(cout);
    while (!s2->isEmpty())
        s2->pop();
    s2->print(cout);
    
    max_size = 10;
    vector<float> vec;

    for (int i = 1; i < max_size; ++i)
        vec.push_back(i);
    
    printVec(vec);
    reverseVec(vec);
    printVec(vec);
}