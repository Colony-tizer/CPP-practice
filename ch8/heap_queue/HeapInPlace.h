#ifndef HEAPINPLACE_H_
#define HEAPINPLACE_H_
#include <vector>
#include <string>
template <class T, class C>
class HeapInPlace {
    private:
        typedef T value_type;
        typedef value_type& ref_type;
        typedef value_type const& const_ref_type;
        typedef value_type* ptr_type;
        
        typedef C comparator;

        typedef std::vector<value_type> tVec;
        typedef tVec& ref_tVec;
        typedef tVec const& const_ref_tVec;
        typedef typename tVec::iterator it_type;
    public:
        HeapInPlace();
        ~HeapInPlace();
        int getSize() const;
        bool isEmpty() const;
        bool isSorted() const;
        const_ref_type getMin() const;
        void add(const_ref_type val);
        void removeLast();
        void sort();
        std::string toString() const;
    protected:
        it_type pos(int i, ref_tVec vec);
        int idx(it_type pos, ref_tVec vec);
        void swap(it_type pos1, it_type pos2);

        bool hasLeft(it_type pos, ref_tVec vec, int size = -1);
        bool hasRight(it_type pos, ref_tVec vec, int size = -1);
        bool isRoot(it_type pos, ref_tVec vec);
        it_type getParent(it_type pos, ref_tVec vec);
        it_type getLeft(it_type pos, ref_tVec vec);
        it_type getRight(it_type pos, ref_tVec vec);
        void mergeToBigTree(it_type pos, ref_tVec bigTree, ref_tVec tree, bool toLeft = true);
        tVec formHeap(ref_tVec vec);
    private:
        tVec vector;
        comparator compObj;
        bool sorted;
};
#include "HeapInPlace.tpp"
#endif