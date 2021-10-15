#include "HeapInPlace.h"
#include <math.h>
#include <sstream>
#include <iostream>
template <class T, class C>
HeapInPlace<T,C>::HeapInPlace() {
    vector = tVec();
    sorted = false;
}
template <class T, class C>
HeapInPlace<T,C>::~HeapInPlace() {
}
template <class T, class C>
int HeapInPlace<T,C>::getSize() const {
    return vector.size();
}
template <class T, class C>
bool HeapInPlace<T,C>::isEmpty() const {
    return getSize() == 0;
}
template <class T, class C>
bool HeapInPlace<T,C>::isSorted() const {
    return sorted;
}
template <class T, class C>
typename HeapInPlace<T,C>::const_ref_type HeapInPlace<T,C>::getMin() const {
    if (!sorted) throw "NotSortedError";
    return vector[0];
}
template <class T, class C>
void HeapInPlace<T,C>::add(const_ref_type val) {
    vector.push_back(val);
    if (sorted) sorted = !sorted;
}
template <class T, class C>
void HeapInPlace<T,C>::removeLast() {
    vector.pop_back();
}
const bool upHeapFlag = true;
template <class T, class C>
void HeapInPlace<T,C>::sort() {
    if (sorted) return;
    auto item = vector.begin();
    int cnt = 0;
    if (upHeapFlag) {
        tVec heap = formHeap(vector);
        vector = heap;
    } else {
        for (cnt; cnt < vector.size(); ++cnt) {
            item = pos(cnt, vector);
            if (cnt != 0) {
                auto parent = getParent(item, vector);
                while (compObj(*item, *parent)) {
                    swap(item, parent);
                    item = parent;
                    if (!isRoot(item, vector)) parent = getParent(item, vector);
                    else break;
                }
            }
        }
    }
    std::cout<<toString()<<std::endl;
    cnt = getSize() - 1;
    for (cnt; cnt > 0; --cnt) {
        item = pos(cnt, vector);
        swap(item, pos(0, vector));
        item = pos(0, vector);
        while (hasLeft(item, vector, cnt)) {
            auto nextItem = getLeft(item, vector);
            if (hasRight(item, vector, cnt) && compObj(*(getRight(item, vector)), *nextItem)) nextItem = getRight(item, vector);
            if (compObj(*nextItem, *item)) {
                swap(nextItem, item);
                item = nextItem;
            } else break;
        }
    }
    sorted = true;
}
template <class T, class C>
std::string HeapInPlace<T,C>::toString() const {
    std::string heapStr = "";
    std::ostringstream converter;
    for (auto it = vector.begin(); it != vector.end(); ++it) {
        if (it != vector.begin()) 
            converter<<", ";
        converter<<*it;
    }
    heapStr = converter.str();
    return heapStr;
}
template <class T, class C>
typename HeapInPlace<T,C>::it_type HeapInPlace<T,C>::pos(int i, ref_tVec vec) {
    ref_tVec workVec = (vec.size() == 0) ? vector : vec;
    return (workVec.begin() + i);
}
template <class T, class C>
int HeapInPlace<T,C>::idx(it_type pos, ref_tVec vec) {
    ref_tVec workVec = (vec.size() == 0) ? vector : vec;
    int diff = pos - workVec.begin();
    return (pos - workVec.begin());
}
template <class T, class C>
void HeapInPlace<T,C>::swap(it_type pos1, it_type pos2) {
    auto temp = *pos1;
    *pos1 = *pos2; 
    *pos2 = temp;
    if (sorted) sorted = !sorted;
}

template <class T, class C>
bool HeapInPlace<T,C>::hasLeft(it_type pos, ref_tVec vec, int size) {
    ref_tVec workVec = (vec.size() == 0) ? vector : vec;
    if (size < 0) size = workVec.size();
    return (2*idx(pos, workVec) + 1 < size);
}
template <class T, class C>
bool HeapInPlace<T,C>::hasRight(it_type pos, ref_tVec vec, int size) {
    ref_tVec workVec = (vec.size() == 0) ? vector : vec;
    if (size < 0) size = workVec.size();
    return (2*idx(pos, workVec) + 2 < size);
}
template <class T, class C>
bool HeapInPlace<T,C>::isRoot(it_type pos, ref_tVec vec) {
    ref_tVec workVec = (vec.size() == 0) ? vector : vec;
    return idx(pos, workVec) == 0;
}
template <class T, class C>
typename HeapInPlace<T,C>::it_type HeapInPlace<T,C>::getParent(it_type pos, ref_tVec vec) {
    ref_tVec workVec = (vec.size() == 0) ? vector : vec;
    int ind = idx(pos, workVec);
    if (ind == 0) throw "NoParentError";
    int pInd = (int)(ceil((double)(idx(pos, workVec))/2));
    return this->pos(std::max(pInd - 1,0), workVec);
}
template <class T, class C>
typename HeapInPlace<T,C>::it_type HeapInPlace<T,C>::getLeft(it_type pos, ref_tVec vec) {
    ref_tVec workVec = (vec.size() == 0) ? vector : vec;
    if (!hasLeft(pos, workVec, workVec.size())) throw "NoChildError";
    return this->pos(2*idx(pos, workVec) + 1, workVec);
}
template <class T, class C>
typename HeapInPlace<T,C>::it_type HeapInPlace<T,C>::getRight(it_type pos, ref_tVec vec) {
    ref_tVec workVec = (vec.size() == 0) ? vector : vec;
    if (!hasRight(pos, workVec, workVec.size())) throw "NoChildError";
    return this->pos(2*idx(pos, workVec) + 2, workVec);
}

template <class T, class C>
void HeapInPlace<T,C>::mergeToBigTree(it_type pos, ref_tVec bigTree, ref_tVec tree, bool toLeft) {
    if (tree.size() == 0) return;
    auto t1_ptr = tree.begin();
    auto ptr = pos;
    do {
        *ptr = *t1_ptr;
        if (hasLeft(t1_ptr, tree)) t1_ptr = getLeft(t1_ptr, tree);
        if (hasLeft(ptr, bigTree)) ptr = getLeft(ptr, bigTree);
    } while (hasLeft(t1_ptr, tree));
    *ptr = *t1_ptr;
    ptr = pos;
    t1_ptr = tree.begin();
    if (hasRight(t1_ptr, tree)) {
        t1_ptr = tree.begin();
        do {
            if (hasRight(ptr, bigTree)) ptr = getRight(ptr, bigTree);
            *ptr = *t1_ptr;
            if (hasRight(t1_ptr, tree)) t1_ptr = getRight(t1_ptr, tree);
        } while (hasRight(t1_ptr, tree));
        *ptr = *t1_ptr;
    }
}
template <class T, class C>
typename HeapInPlace<T,C>::tVec HeapInPlace<T,C>::formHeap(ref_tVec vec) {
    if (vec.size() == 0) return vec;
    auto el = *(vec.begin());
    vec.erase(vec.begin());
    
    const int midInd = floor(vec.size() / 2);
    tVec vec1, vec2, t1, t2, t3;
    if (vec.size() > 0) {
        vec1 = tVec(vec.begin(), vec.begin() + std::max(midInd, 1));
        if (vec.size() > 1) vec2 = tVec(vec.begin() + std::max(midInd, 1), vec.end());
        t1 = formHeap(vec1);
        t2 = formHeap(vec2);
    }
    const int t3Size = t1.size() + t2.size() + 1;
    t3 = tVec(t3Size);
    t3[0] = el;
    auto t1_ptr = t1.begin();
    auto t2_ptr = t2.begin();
    auto ptr = t3.begin();
    if (hasLeft(ptr, t3)) mergeToBigTree(getLeft(ptr, t3), t3, t1);
    if (hasRight(ptr, t3)) mergeToBigTree(getRight(ptr, t3), t3, t2);
    // down-heap bubble from root
    auto rootItem = t3.begin();
    while (hasLeft(rootItem, t3, t3Size)) {
        auto nextPos = getLeft(rootItem, t3);
        if (hasRight(rootItem, t3, t3Size) && compObj(*(getRight(rootItem, t3)), *nextPos)) 
            nextPos = getRight(rootItem, t3);
        if (compObj(*nextPos, *rootItem)) {
            swap(nextPos, rootItem);
            rootItem = nextPos;
        } else break;
    }
    return t3;
}