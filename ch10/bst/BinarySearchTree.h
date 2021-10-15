#ifndef BST_H_
#define BST_H
#include "../../ch9/map/Entry.h"
#include "../../ch7/binary_tree/BTree.h"
template <class T> class BTree;
// type E should contain Key and Value props
template <class E> 
class BinarySearchTree {
    public:
        typedef typename E::Key EntryKey;
        typedef typename E::Value EntryValue;
        class Iterator;
    protected:
        typedef BTree<E> BinaryTree;
        typedef typename BinaryTree::BTreePosition BTreePosition;
    public:
        BinarySearchTree();
        int size() const;
        bool empty() const;
        Iterator find(const EntryKey& key);
        Iterator insert(const EntryKey& key, const EntryValue& value);
        void erase(const EntryKey& key);
        void erase(const Iterator& pointer);
        Iterator begin();
        Iterator end();
    protected:
        BTreePosition root() const;
        BTreePosition finder(const EntryKey& key, const BTreePosition& node);
        BTreePosition inserter(const EntryKey& key, const EntryValue& value);
        BTreePosition eraser(const BTreePosition& node);
        BTreePosition restructure(const BTreePosition& node);
    private:
        BinaryTree _tree;
        int _size;
};
#include "BinarySearchTree.tpp"
#endif