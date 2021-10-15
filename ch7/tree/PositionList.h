#ifndef POSITIONLIST_H_
#define POSITIONLIST_H_
#include "../../ch6/list/NodeList.h"
#include "Position.h"
template <class T> class NodeList;
template <class T> class Position;
template <class T>
class PositionList : public NodeList<Position<T>> {
    private:
        typedef NodeList<Position<T>> list_value_type;
    public:
        PositionList() {}
    private:

};
#endif