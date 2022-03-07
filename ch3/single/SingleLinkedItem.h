#ifndef SINGLE_LINKED_ITEM_H_

#define SINGLE_LINKED_ITEM_H_
#include <string>
#include <ostream>

template <class T>
class SingleLinkedItem {
    public:
        typedef T Value_t;
        typedef T& Ref_t;
        typedef T const& Ref_const_t;
        typedef T* Prt_t;

        SingleLinkedItem() : next(nullptr) {
            value = Value_t();
        }

        SingleLinkedItem(Ref_const_t val) : next(nullptr) {
            value = val;
        }

        SingleLinkedItem(Ref_t val) : next(nullptr) {
            value = val;
        }

        SingleLinkedItem(const SingleLinkedItem &item) {
            value = item.value; next = item.next;
        }

        ~SingleLinkedItem() {}

        inline Ref_const_t getValue() const {
            return this->value;
        }

        inline SingleLinkedItem* getNext() const {
            return next;
        }

        inline void setValue(Ref_const_t val) {
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
        Value_t value;
        SingleLinkedItem *next;
        
};
#endif