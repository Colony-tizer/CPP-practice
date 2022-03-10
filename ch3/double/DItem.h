#ifndef DITEM_H_

#define DITEM_H_

#include <ostream>
#include <string>
#include "DList.h"

template <typename T>
class DItem {
    public:
        typedef T Value_t;
        typedef T& Ref_t;
        typedef T const& Ref_const_t;
        typedef T* Ptr_t;

        DItem() : value(), prev(nullptr), next(nullptr) {}
        DItem(Ref_const_t val) : value(val), prev(nullptr), next(nullptr) {}
        DItem(const DItem<T>& obj) : value(obj.value), prev(obj.prev), next(obj.next) {}
        ~DItem() {}
        
        inline Ref_const_t getValue() const {
            return value;
        }

        inline DItem* getNext() {
            return next;
        }

        inline DItem* getPrev() {
            return prev;
        }
        
        inline void setValue(Ref_const_t val){
            value = val;
        }

        inline void setNext(const DItem& item) {
            next = new DItem<T>(item);
        }

        inline void setNext(DItem* item) {
            next = item;
        }

        inline void setPrev(const DItem& item) {
            prev = new DItem<T>(item);
        }
        
        inline void setPrev(DItem* item) {
            prev = item;
        }

        std::string toString() {
            std::string itemStr = "NULL <==> ";
            DItem *curObj = this;

            while (curObj->prev) curObj = curObj->prev;

            while (curObj) {
                if (curObj == this) itemStr += "| " + curObj->value + " |";
                else itemStr += curObj->value;
                itemStr += " <==> ";
                curObj = curObj->next;
            }
            itemStr += "NULL\n";
            return itemStr;
        }

        std::ostream& print(std::ostream& os) {
            os<<toString();
            return os;
        }
    private:
        Value_t value;
        DItem *prev;
        DItem *next;
};

#endif