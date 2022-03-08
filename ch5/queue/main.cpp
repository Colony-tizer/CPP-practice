#include "Queue.h"
#include "QueueCL.h"
#include "QueueD.h"
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void fillArray(T* array, const uint size, const int modifier = 1) {
    for (size_t i = 0; i < size; ++i)
        array[i] = (i + 1) * modifier;
}

template <typename T>
void printArray(T* array, const uint size) {
    for (size_t i = 0; i < size; ++i) {
        if (i != 0) cout << ", ";
        cout << array[i];
    }
    cout << endl;
}

void testQueueEnqueue() {
    cout << "Testing queue. Creating a queue..." << endl;
    Queue<int*> queue(10);
    cout << "Queue has been successfully created!" << endl << endl;

    cout << "Getting front item from the empty queue..." << endl;
    try {
        queue.front();
    } catch (QueueEmptyError& ex) {
        cout << "Cannot get the front item:" << endl;
        cout << ex.what() << endl << endl;
    }

    const uint ARRAY_SIZE = 10;

    int *array = new int[ARRAY_SIZE];
    fillArray(array, ARRAY_SIZE);

    cout << "Adding an item to the queue..." << endl;
    queue.enqueue(array);
    cout << "Item has been successfully added!" << endl << endl;

    cout << "Getting the front item of the queue..." << endl << endl;
    int *front = queue.front();

    cout << "The content of the returned item:" << endl;
    printArray(front, ARRAY_SIZE);
    
    delete front;

    cout << "Removing the item from the queue..." << endl;
    queue.dequeue();
    cout << "Item has been successfully removed!" << endl << endl;

    cout << "Removing element from empty queue..." << endl;
    try {
        queue.dequeue();
    } catch (QueueEmptyError& ex) {
        cout << "Cannot dequeue:" << endl;
        cout << ex.what() << endl << endl;
    }
}

void testEnqueueDequeueCircular() {
    cout << "Testing queue based on Circular list. Creating a queue..." << endl;
    QueueCL<string> queueCircular;
    cout << "Queue has been successfully created!" << endl << endl;
    
    cout << "Adding two elements to the queue..." << endl;
    queueCircular.enqueue("first!");
    queueCircular.enqueue("second...");
    cout << "Items have been successfully added!" << endl << endl;

    cout << "The contents of the queue:" << endl;
    cout << queueCircular.toString() << endl;
    
    cout << "Removing all items from the queue..." << endl << endl;
    while (!queueCircular.isEmpty()) {
        queueCircular.dequeue();
        cout << "Removed an item. The contents of the queue:" << endl;
        cout << queueCircular.toString() << endl;
    }
    cout << "All items have been successfully removed!" << endl;
}

void testEnqueueDequeueDoubleLinkedQueue() {
    cout << "Testing queue based on Double Linked list. Creating a queue..." << endl;
    QueueD<string> queueDoubleLinked;
    cout << "Queue has been successfully created!" << endl << endl;
    
    cout << "Adding three elements to the queue..." << endl;
    queueDoubleLinked.insertFront("oi");
    queueDoubleLinked.insertFront("aye");
    queueDoubleLinked.insertBack("i'm back!");
    cout << "Items have been successfully added!" << endl << endl;

    cout << "The contents of the queue:" << endl;
    cout << queueDoubleLinked.toString() << endl;
    
    cout << "The front item:" << endl;
    cout << queueDoubleLinked.front() << endl;
    cout << "The back item:" << endl;
    cout << queueDoubleLinked.back() << endl << endl;

    cout << "Removing all items from the queue..." << endl << endl;
    while (!queueDoubleLinked.isEmpty()) {
        queueDoubleLinked.removeBack();
        cout << "Removed an item. The contents of the queue:" << endl;
        cout << queueDoubleLinked.toString() << endl;
    }
    cout << "All items have been successfully removed!" << endl;
}

int main() {
    testQueueEnqueue();
    cout << endl << "===================================" << endl << endl;
    testEnqueueDequeueCircular();
    cout << endl << "===================================" << endl << endl;
    testEnqueueDequeueDoubleLinkedQueue();

    return 0;
}
