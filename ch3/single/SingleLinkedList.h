#ifndef SINGLE_LINKED_LIST_H_

#define SINGLE_LINKED_LIST_H_

#include <ostream>
#include "SingleLinkedItem.h"
template <class T> class SingleLinkedItem;

template <class T>
class SingleLinkedList {
    private:    
        typedef SingleLinkedItem<T> item_type;
        typedef item_type* item_ptr;
        typedef item_type& item_ref;
        typedef item_type const& item_const_ref;
    public:
        typedef typename item_type::value_type value_type;
        typedef typename item_type::ref_type ref_type;
        typedef typename item_type::const_ref_type const_ref_type;
        typedef typename item_type::ptr_type ptr_type;

        SingleLinkedList();
        ~SingleLinkedList();
        bool isEmpty();
        void removeFront();

        item_const_ref front() const;
        const_ref_type frontVal() const;
        void addFront(item_const_ref obj);
        void addFront(const_ref_type val);
        

        friend std::ostream& operator<<(std::ostream& os, SingleLinkedList& obj) {
            item_ptr printObj = obj.head;
            if (printObj)
                printObj->print(os)<<"\n";
            else 
                os<<"NULL\n";
            return os;
        }
    private:
        item_ptr head;
};
#include "SingleLinkedList.tpp"
#endif