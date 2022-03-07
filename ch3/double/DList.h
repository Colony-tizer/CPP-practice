#ifndef DLIST_H_
#define DLIST_H_

#include "DItem.h"
#include <ostream>
#include <string>

template <typename T> class DItem;

template <typename T> 
class DList {
    private:
        typedef DItem<T> DItem_t;
        typedef DItem_t& DItem_ref_t;
        typedef const DItem_t& DItem_ref_const_t;
        typedef DItem_t* DItem_ptr_t;

    public:
        typedef typename DItem_t::Value_t Value_t;
        typedef typename DItem_t::Ptr_t Ptr_t;
        typedef typename DItem_t::Ref_t Ref_t;
        typedef typename DItem_t::Ref_const_t Ref_const_t;

        DList() : size(0), head(nullptr), tail(nullptr) {}
        DList(Ref_const_t val);
        DList(DItem_ref_const_t obj);
        ~DList();

        bool isEmpty() const;
        int getSize() const;

        Ref_const_t front() const;
        Ref_const_t at(const int i) const;

        void addAt(const int i, Ref_const_t val);
        void addAt(const int i, DItem_ref_const_t item);

        void addFront(Ref_const_t val);
        void addFront(DItem_ref_const_t item);

        void removeAt(const int i);
        void popFront(); 

        std::string toString() {
            return head->toString();
        }

        friend std::ostream& operator<<(std::ostream& os, DList& list) {
            DItem_ptr_t obj = list.head;
            if (obj)
                obj->print(os);
            else os<< "NULL";
            return os;
        }

    private:
        DItem_ptr_t getItemAt(const int i) const; 

    private:
        DItem_ptr_t head;
        DItem_ptr_t tail;
        int size;
};

#include "DList.tpp"

#endif