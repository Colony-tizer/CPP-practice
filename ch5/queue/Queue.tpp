#include "Queue.h"
#include "Exceptions.h"

template <typename T>
Queue<T>::Queue(const uint16_t capacity /*= 10*/) {
    this->capacity = capacity;
    array = new Value_t[capacity];
    firstIndex = lastIndex = 0;
    queueSize = 0;
}

template <typename T>
Queue<T>::~Queue() {
    delete[] array;
}

template <typename T>
bool Queue<T>::isEmpty() const {
    return getSize() == 0;
}

template <typename T>
uint16_t Queue<T>::getSize() const {
    return queueSize;
}

template <typename T>
typename Queue<T>::Ref_const_t Queue<T>::front() const {
    if (isEmpty()) throw QueueEmptyError();

    return array[firstIndex];
}

template <typename T>
typename Queue<T>::Ref_const_t Queue<T>::last() const {
    if (isEmpty()) throw QueueEmptyError();

    return array[lastIndex];
}

template <typename T>
void Queue<T>::dequeue() {
    if (isEmpty()) throw QueueEmptyError();

    firstIndex = (firstIndex + 1) % capacity;

    --queueSize;
}

template <typename T>
void Queue<T>::enqueue(Queue<T>::Ref_const_t val) {
    if (queueSize == capacity) throw QueueFullError();

    array[lastIndex] = Value_t(val);
    lastIndex = (lastIndex + 1) % capacity;

    ++queueSize;
}