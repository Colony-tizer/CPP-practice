#include "CompleteTree.h"
template <class T>
CompleteTree<T>::CompleteTree() : list(1) {}
template <class T>
CompleteTree<T>::~CompleteTree() {}
template <class T>
int CompleteTree<T>::getSize() const {
    return list.size() - 1;
}
template <class T>
bool CompleteTree<T>::isEmpty() const {
    return getSize() == 0;
}
template <>
std::string CompleteTree<int>::toString() const {
    std::string treeStr = "";
    int cnt = 1;
    for (auto it = list.begin() + 1; it != list.end(); ++it, ++cnt) {
        if (cnt != 1) treeStr += ", ";
        treeStr += "[" + std::to_string(cnt);
        treeStr += "]: " + std::to_string(*it);
    }   
    return treeStr;
}
template <class T>
bool CompleteTree<T>::hasLeft(const_ref_list_pos pos) {
    return (2 * idx(pos) <= getSize());
}
template <class T>
bool CompleteTree<T>::hasRight(const_ref_list_pos pos) {
    return (2 * idx(pos) + 1 <= getSize());
}
template <class T>
bool CompleteTree<T>::isRoot(const_ref_list_pos pos) {
    return idx(pos) == 1;
}
template <class T>
typename CompleteTree<T>::list_pos CompleteTree<T>::getLeft(const_ref_list_pos pos) {
    return this->pos(2*idx(pos));
}
template <class T>
typename CompleteTree<T>::list_pos CompleteTree<T>::getRight(const_ref_list_pos pos) {
    return this->pos(2*idx(pos) + 1);
}
template <class T>
typename CompleteTree<T>::list_pos CompleteTree<T>::getParent(const_ref_list_pos pos) {
    if (idx(pos) == 1) throw "NoParentError";
    return this->pos(idx(pos)/2);
}
template <class T>
typename CompleteTree<T>::list_pos CompleteTree<T>::getRoot() {
    if (getSize() == 0) throw "EmptyTreeError";
    return this->pos(1);
}
template <class T>
typename CompleteTree<T>::list_pos CompleteTree<T>::getLast() {
    return pos(getSize());
}
template <class T>
typename CompleteTree<T>::list_pos CompleteTree<T>::at(int i) {

}
template <class T>
void CompleteTree<T>::add(const_ref_type val) {
    list.push_back(val);
}
template <class T>
void CompleteTree<T>::removeLast() {
    list.pop_back();
}
template <class T>
void CompleteTree<T>::swap(const_ref_list_pos pos1, const_ref_list_pos pos2) {
    value_type swapVal = *pos1;
    *pos1 = *pos2; *pos2 = swapVal;  
}
template <class T>
typename CompleteTree<T>::list_pos CompleteTree<T>::pos(int i) {
    return (list.begin() + i);
}
template <class T>
int CompleteTree<T>::idx(const_ref_list_pos pos) const {
    return (pos - list.begin());
}