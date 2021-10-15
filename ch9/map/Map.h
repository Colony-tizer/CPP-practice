#ifndef MAP_H_
#define MAP_H_
#include "../../ch6/list/NodeList.h"
#include "Entry.h"
template <class T> class NodeList;
template <class K, class V> class Entry;

template <class K, class V>
class Map {
    private:
        typedef Entry<K,V> val_entry;
        typedef val_entry& ref_entry;
        typedef val_entry const& const_ref_entry;
        typedef val_entry* ptr_entry;

        typedef NodeList<val_entry> val_list;

        typedef Iterator<val_entry> it_type;
        typedef it_type& ref_it_type;
        typedef it_type const& const_ref_it_type;
    public: 
        Map() : _list() {}
        ~Map() {}
        bool isEmpty() const { return getSize() == 0; }
        int getSize() const { return _list.getSize(); }
        it_type find(const K& key) { 
            auto it = _list.begin();
            for (it; it != _list.end(); ++it) 
                if ((*it).key() == key) break;
            return it;
        }
        it_type put(const K& key, const V& val) {
            auto existed = find(key);
            if (existed == end()) _list.insertBack(val_entry(key, val));
            else (*existed).setValue(val);
            return _list.begin() + (getSize() - 1);
        }
        void erase(const K& key) {
            _list.remove(find(key));
        }
        void erase(const_ref_it_type it) {
            _list.remove(it);
        }
        it_type begin() { return _list.begin(); }
        it_type end() { return _list.end(); }
    private:
        val_list _list;
};
#include "Map.tpp"
#endif