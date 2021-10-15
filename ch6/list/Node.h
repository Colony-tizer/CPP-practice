#ifndef NODE_H_
#define NODE_H
template <class T>
struct Node {
    T value;
    Node *prev;
    Node *next;

    Node() : value(), prev(nullptr), next(nullptr) {}
    Node(T const& val) : value(val), prev(nullptr), next(nullptr) {}
    Node(Node* obj) : value(obj->value), prev(obj->prev), next(obj->next) {}
};

#endif