#ifndef LISTPRIORITYQUEUE_H_
#define LISTPRIORITYQUEUE_H_
#include <list>

template <class T, class C>
class ListPriorityQueue {
    private:
        typedef T value_type;
        typedef value_type& ref_type;
        typedef value_type const& const_ref_type;
        typedef value_type* ptr_type;


        typedef C comparator;
    public:
        ListPriorityQueue();
        ~ListPriorityQueue();
        int getSize() const;
        bool isEmpty() const;
        const_ref_type getMin() const;
        void removeMin();
        void insert(const_ref_type val);
    private:
        std::list<value_type> list;
        comparator isLess;
};

#include "ListPriorityQueue.tpp"

#endif