#ifndef QUEUE_H_
#define QUEUE_H_

template <class T>
class Queue {
    private:
        typedef T value_type;
        typedef T* ptr_type;
        typedef T& ref_type;
        typedef T const& const_ref_type;
    public:
        Queue(const int capacity = 10);
        ~Queue();
        bool isEmpty() const;
        int getSize() const;
        const_ref_type front() const;
        const_ref_type last() const;
        void dequeue();
        void enqueue(const_ref_type val);
    private:
        ptr_type array;
        int capacity;
        int queueSize;
        int firstIndex;
        int lastIndex;
};

#include "Queue.tpp"

#endif