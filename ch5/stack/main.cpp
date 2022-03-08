#include <iostream>
#include <vector>
#include "Stack.h"
#include "StackSList.h"
using namespace std;

template <typename T>
void fillStack(AStack<T> &stack, const int size) {
    for (int i = 1; i <= size; ++i) {
        stack.push(i);
    }
}

template <typename T>
void reverseVec(vector<T> &vec) {
    const int size = vec.size();
    Stack<T> bufferStack(size);

    size_t i = 0;

    for (i = 0; i < size; ++i)
        bufferStack.push(vec.at(i));

    for (i = 0; i < size; ++i) {
        vec[i] = bufferStack.top();
        bufferStack.pop();
    }
}

template <typename T>
void printVec(vector<T> &vec) {
    for (int i = 0; i < vec.size(); ++i)
        cout << vec.at(i) << " ";
    cout << endl;
}

void testFullExceptionStack() {
    const uint8_t STACK_CAPACITY_SIZE = 10;

    cout << "FullStackException test..." << endl;
    Stack<int> stack(STACK_CAPACITY_SIZE);

    fillStack(stack, STACK_CAPACITY_SIZE);
    cout << "Current size of the stack: " << stack.getSize() << endl;

    cout << "Adding one more item..." << endl;
    try {
        stack.push(11); // expected error
    } catch(StackFullException &e) {
        cout << e.what() << endl;
    }
    cout << endl;
}

void testEmptyExceptionStack() {
    const uint8_t STACK_CAPACITY_SIZE = 3;

    cout << "EmptyStackException test..." << endl;
    Stack<float> stack(STACK_CAPACITY_SIZE);
    cout << "Trying to get top item..." << endl;
    try {
        cout << stack.top(); // expected error
    } catch(StackEmptyException &e) {
        cout << e.what() << endl;
    }
    cout << endl;
}

void testStackSList() {
    const uint8_t PUSH_ITEMS_QUANTITY = 100;

    StackSList<double> stack;
    fillStack(stack, PUSH_ITEMS_QUANTITY);

    cout << "The stack is filled: " << endl;
    stack.print(cout);

    cout << endl;
    cout << "Clearing the stack..." << endl;
    while (!stack.isEmpty())
        stack.pop();

    cout << "The stack is cleared! The current content of the stack: " << endl;
    stack.print(cout);
    cout << endl << endl;
}

void reverseVectorWithStack() {
    const uint8_t STACK_CAPACITY_SIZE = 3;

    cout << "Reversing vector using stack..." << endl;
    vector<float> vec;

    for (size_t i = 0; i < STACK_CAPACITY_SIZE; ++i)
        vec.push_back(i);

    cout << "Current vector: " << endl;
    printVec(vec);
    cout << endl << "Reversing vector..." << endl << endl;
    reverseVec(vec);
    cout << "Reversed vector: " << endl;
    printVec(vec);
}

int main() {
    testFullExceptionStack();
    testEmptyExceptionStack();
    testStackSList();
    reverseVectorWithStack();

    return 0;
}