#ifndef POSITION_H_
#define POSITION_H_
#include "PositionList.h"

template <class T> class PositionList;

template <class T>
class Position {
    private:
        typedef T value_type;
        typedef value_type* ptr_type;
        typedef value_type& ref_type;
        typedef value_type const& const_ref_type;

        typedef PositionList<T> value_list_type;
        typedef value_list_type* ptr_list_type;
        typedef value_list_type& ref_list_type;
        typedef value_list_type const& const_ref_list_type;
    public:
        Position() : value(), parent(nullptr), children() {}
        Position(const_ref_type val) : value(val), parent(nullptr), children() {}
        Position(const Position& obj) : value(obj.value), parent(obj.parent), children(obj.children) {}
        ~Position() { 
            delete children; 
            if (parent) parent->children = nullptr;
        }
        ref_type operator*() { return value; }
        Position getParent() const { return *parent; }
        ref_list_type getChildren() const { return children; }
        void setParent(const Position& pos) { parent = new Position<T>(pos); parent->getChildren().insertBack(*this); }
        void setParent(Position* pos) { parent = pos; parent->getChildren().insertBack(*this); }
        void removeParent() { 
            if (!getParent()) return; 
            auto parentChilds = parent->getChildren();
            auto it = parentChilds.begin();
            while (*it != *this)
                ++it;
            parent->getChildren().remove(it);
            parent = nullptr;
        }
        void setChildren(const_ref_list_type list) {
            delete children; 
            children = new value_list_type(list);
            for (auto it = list.begin(); it != list.end() ++it)
                *it.setParent(this);
        }
        void addChildren(const Position& pos) {
            if (!children) children = new value_list_type();
            children->insertBack(pos);
        }
        void removeChildren(const Position& pos) {
            auto it = children.begin();
            while (*it != pos)
                ++it;
            children->remove(it);
        }
        void clearChildren() { delete children; children = nullptr; }
        bool isRoot() const { return parent == nullptr; }
        bool isExternal() const { return children.isEmpty(); }
        int getSize() const {
            int size = 1;
            if (children) {
                for (auto it = children->begin(); it != children->end(); ++it) {
                    auto pos = *it;
                    size += pos.getSize();
                }
            }
            return size;
        }
        
    private:
        value_type value;
        Position *parent;
        ptr_list_type children;
};
#endif