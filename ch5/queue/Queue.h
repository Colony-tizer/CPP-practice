#ifndef QUEUE_H_
#define QUEUE_H_ 
#include <cstdint>

template <typename T>
class Queue {
    private:
        typedef T Value_t;
        typedef T* Ptr_t;
        typedef T& Ref_t;
        typedef T const& Ref_const_t;

    public:
        Queue(const uint16_t capacity = 10);
        ~Queue();

        bool isEmpty() const;
        uint16_t getSize() const;
        Ref_const_t front() const;
        Ref_const_t last() const;

        void dequeue();
        void enqueue(Ref_const_t val);

    private:
        Ptr_t array;
        uint16_t capacity;
        uint16_t queueSize;
        uint16_t firstIndex;
        uint16_t lastIndex;
};

#include "Queue.tpp"

#endif