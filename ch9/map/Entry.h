#ifndef MAPENTRY_H_
#define MAPENTRY_H_
template <class K, class V>
class Entry {
    public:
        typedef K Key;
        typedef V Value;
    public:
        Entry(const K& key = K(), const V& val = V()) : _key(key), _val(val) {}
        const K& key() const { return _key; }
        const V& value() const { return _val; }
        void setKey(const K& key) { _key = key; }
        void setValue(const V& val) { _val = val; }
    private:
        K _key;
        V _val;
};
#endif