#ifndef ABSTRACT_MAP_CLASS
#define ABSTRACT_MAP_CLASS

// heavily based on example from book

template<typename Key, typename Value> 
class Map 
{
public:
    
    class Entry {
        friend Map;
    private:
        Key k;
        Value v;

    public:
        Entry(const Key& k = Key(), const Value& v = Value()) : k(k), v(v) {}
        const Key& key() const { return k;}
        const Value& value() const { return v; }
        Value& value() { return v; }
    };

    class const_iterator 
    {
        friend Map;
    public:
        const_iterator++(int) {const_iterator temp{*this}; rep->advance(); return temp;}
    }    

};
#endif
