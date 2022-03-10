#ifndef SINGLE_LINKED_ITEM_H_

#define SINGLE_LINKED_ITEM_H_
#include <string>
#include <ostream>

template <typename T>
class SingleLinkedItem {
    public:
        typedef T Value_t;
        typedef T& Ref_t;
        typedef T const& Ref_const_t;
        typedef T* Ptr_t;

        SingleLinkedItem() : next(nullptr) {
            value = Value_t();
        }

        SingleLinkedItem(Ref_const_t val) : next(nullptr) {
            value = val;
        }

        SingleLinkedItem(Ref_t val) : next(nullptr) {
            value = val;
        }

        SingleLinkedItem(const SingleLinkedItem<T> &item) {
            value = item.value; next = item.next;
        }

        ~SingleLinkedItem() {}

        inline Ref_const_t getValue() const {
            return this->value;
        }

        inline SingleLinkedItem<T>* getNext() const {
            return next;
        }

        inline void setValue(Ref_const_t val) {
            value = val;
        }

        inline void setNext(const SingleLinkedItem<T> &item) {
            next = new SingleLinkedItem<T>(item);
        }

        inline void setNext(SingleLinkedItem<T> *item) {
            next = item;
        }

        friend std::ostream& operator<<(std::ostream& os, const SingleLinkedItem<T>& obj) {
            SingleLinkedItem<T>::Value_t printObj = obj.value;

            os << obj.getValue(); 
            if (obj.next) {
                os << " -> ";
                os << (*obj.getNext());
            }

            return os;
        }
    private:
        Value_t value;
        SingleLinkedItem *next;
        
};
#endif