#include "Queue.h"
#include "Exceptions.h"

template <class T>
Queue<T>::Queue(const int capacity) {
    this->capacity = capacity;
    array = new value_type[capacity];
    firstIndex = lastIndex = 0;
    queueSize = 0;
}
template <class T>
Queue<T>::~Queue() {
    delete[] array;
}
template <class T>
bool Queue<T>::isEmpty() const {
    return getSize() == 0;
}
template <class T>
int Queue<T>::getSize() const {
    return queueSize;
}
template <class T>
typename Queue<T>::const_ref_type Queue<T>::front() const {
    if (isEmpty()) throw QueueEmptyError();
    return array[firstIndex];
}
template <class T>
typename Queue<T>::const_ref_type Queue<T>::last() const {
    if (isEmpty()) throw QueueEmptyError();
    return array[lastIndex];
}
template <class T>
void Queue<T>::dequeue() {
    if (isEmpty()) throw QueueEmptyError();

    firstIndex = (firstIndex + 1) % capacity;
    --queueSize;
}
template <class T>
void Queue<T>::enqueue(Queue<T>::const_ref_type val) {
    if (queueSize == capacity) throw QueueFullError();
    
    array[lastIndex] = value_type(val);
    lastIndex = (lastIndex + 1) % capacity;
    
    ++queueSize;
}