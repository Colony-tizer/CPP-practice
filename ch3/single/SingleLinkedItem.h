#ifndef SINGLE_LINKED_ITEM_H_

#define SINGLE_LINKED_ITEM_H_
#include <string>
#include <ostream>

template <class T>
class SingleLinkedItem {
    public:
        typedef T value_type;
        typedef T& ref_type;
        typedef T const& const_ref_type;
        typedef T* ptr_type;

        SingleLinkedItem() : next(nullptr) {
            value = value_type();
        }

        SingleLinkedItem(const_ref_type val) : next(nullptr) {
            value = val;
        }

        SingleLinkedItem(ref_type val) : next(nullptr) {
            value = val;
        }

        SingleLinkedItem(const SingleLinkedItem &item) {
            value = item.value; next = item.next;
        }

        ~SingleLinkedItem() {}

        inline const_ref_type getValue() const {
            return this->value;
        }

        inline SingleLinkedItem* getNext() const {
            return next;
        }

        inline void setValue(const_ref_type val) {
            value = val;
        }

        inline void setNext(const SingleLinkedItem &item) {
            next = new SingleLinkedItem<T>(item);
        }

        inline void setNext(SingleLinkedItem *item) {
            next = item;
        }
        std::string toString() {
            std::string items = value + " >> ";
            if (next)
                items += next->toString();
            else items += "NULL";
            return items;
        }
        std::ostream& print(std::ostream &os) {
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