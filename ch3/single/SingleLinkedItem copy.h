#ifndef SINGLE_LINKED_ITEM_H_

#define SINGLE_LINKED_ITEM_H_
#include <ostream>
#include "SingleLinkedList.h"

template <class T>
class SingleLinkedItem {
    template <class U> friend class SingleLinkedList;
    public:
        typedef T value_type;
        typedef T& ref_type;
        typedef T const& const_ref_type;
        typedef T* ptr_type;

        SingleLinkedItem() : next(nullptr) {
            value = T();
        }
        SingleLinkedItem(const_ref_type val) : next(nullptr) {
            value = val;
        }
        SingleLinkedItem(ref_type val) : next(nullptr) {
            value = val;
        }
        SingleLinkedItem(const SingleLinkedItem<T> &obj) {
            value = obj.value; next = obj.next;
        }
        ~SingleLinkedItem() {}
        
        std::ostream& print(std::ostream& os) {
            os<<value<<" -> ";
            if (next)
                next->print(os);
            else
                os<<"NULL\n";
            return os;
        }
    private:
        value_type value;
        SingleLinkedItem *next;
        
};
#endif