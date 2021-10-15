#include "ListPriorityQueue.h"
#include "../../ch5/queue/Exceptions.h"

template <class T, class C>
ListPriorityQueue<T,C>::ListPriorityQueue() {
    list = std::list<value_type>();
}
template <class T, class C>
ListPriorityQueue<T,C>::~ListPriorityQueue() {}
template <class T, class C>
int ListPriorityQueue<T,C>::getSize() const {
    return list.size();
}
template <class T, class C>
bool ListPriorityQueue<T,C>::isEmpty() const {
    return list.empty();
}
template <class T, class C>
typename ListPriorityQueue<T,C>::const_ref_type ListPriorityQueue<T,C>::getMin() const {
    return list.getRoot();
}
template <class T, class C>
void ListPriorityQueue<T,C>::removeMin() {
    if (isEmpty()) throw QueueEmptyError();
    list.pop_front();
}
template <class T, class C>
void ListPriorityQueue<T,C>::insert(const_ref_type val) {
    auto it = list.begin();
    while (it != list.end() && !isLess(val, *it)) ++it;
    list.insert(it, val);
}