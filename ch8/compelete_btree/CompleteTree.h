#ifndef COMPLETETREE_H_
#define COMPLETETREE_H_
#include <vector>
#include <string>

template <class T>
class CompleteTree {
    private:
        typedef T value_type;
        typedef value_type& ref_type;
        typedef value_type const& const_ref_type;
        typedef value_type* ptr_type;

        typedef std::vector<value_type> template_list; 
        typedef typename template_list::iterator list_pos;
        typedef list_pos& ref_list_pos;
        typedef list_pos const& const_ref_list_pos;
    public:
        inline CompleteTree();
        inline ~CompleteTree();
        inline int getSize() const;
        inline bool isEmpty() const;
        std::string toString() const;
        bool hasLeft(const_ref_list_pos pos);
        bool hasRight(const_ref_list_pos pos);
        bool isRoot(const_ref_list_pos pos);
        list_pos getLeft(const_ref_list_pos pos);
        list_pos getRight(const_ref_list_pos pos);
        list_pos getParent(const_ref_list_pos pos);
        list_pos getRoot();
        list_pos getLast();
        list_pos at(int i);
        void add(const_ref_type val);
        void removeLast();
        void swap(const_ref_list_pos pos1, const_ref_list_pos pos2);
    protected:
        inline list_pos pos(int i);
        inline int idx(const_ref_list_pos pos) const;
    private:
        template_list list;
};
#include "CompleteTree.tpp"
#endif