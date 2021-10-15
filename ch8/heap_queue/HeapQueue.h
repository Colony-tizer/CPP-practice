#ifndef HEAPQUEUE_H_
#define HEAPQUEUE_H_
#include "../compelete_btree/CompleteTree.h"
#include <string>

template <class T> class CompleteTree;

// C - comparator
template <class T, class C>
class HeapQueue {
    private:
        typedef T value_type;
        typedef value_type& ref_type;
        typedef value_type const& const_ref_type;
        typedef value_type* ptr_type;

        typedef C comparator;

        typedef CompleteTree<value_type> comp_btree;
    public:
        HeapQueue();
        ~HeapQueue();
        int getSize() const;
        bool isEmpty() const;
        const_ref_type getMin();
        std::string toString();
        void insert(const_ref_type val);
        void removeMin();
    protected:
        const_ref_type getNextValue(const_ref_type val) const;
    private:
        comp_btree tree;
        comparator isLess;
};
#include "HeapQueue.tpp"
#endif