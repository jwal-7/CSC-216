// don't worry about making this truly generic you are limited by the # of characters in alphabet, base 10 numbers, and punctuation/special characters
/* recommended order:
    1. make function
    2. make hashmap
    3. swap cpp hashmap for my hashmap
*/

#ifndef PERSONAL_HASHMAP_CLASS
#define PERSONAL_HASHMAP_CLASS

#include <iostream>
#include <list>
#include <vector>

template <typename Key, typename Value>
class Hashmap 
{
private:
    // ------------- NESTED CLASSES ------------------------------
    class Entry 
    {
    private:
        Key k;
        Value v;

    public:
        Entry(const Key& k = Key(), const Value& v = Value()) : k(k), v(v) {}
        const Key& key() const { return k;}
        const Value& value() const { return v; }
        Value& value() { return v; }
        void set_value(const Value& new_value)  { v = new_value; }
    };

    class Bucket 
    {
    private:
        std::list<Entry> entries;

    public:

        Bucket() : entries{} {}   

        auto find(const Key& k) {
            auto walk = entries.begin();
            while (walk != entries.end() && !(walk->key() == k)) {
                ++walk;
            }
            return walk;
        }
        
        const auto find(const Key& k) const {
            auto walk = entries.begin();
            while (walk != entries.end() && !(walk->key() == k)) {
                ++walk;
            }
            return walk;
        }
        

        bool put(const Key& k, const Value& v) // true = value added, false = value overwritten
        {
            auto walk = find(k);
            if (walk != entries.end()) {
                walk->set_value(v);
                return false;
            } else {
                entries.push_back(Entry(k,v));
                return true;
            }
        } 

        bool contains(const Key& k) const {
            return find(k) != entries.end();
        }

        bool erase(const Key& k) { // true = value removed, false = nothing deleted
            auto found = find(k);
            if (found == entries.end()) { // found at end, do nothing
                return false;
            } else {
                entries.erase(found);   
                return true;
            }   
        }

        void clear() 
        {
            entries.clear();
        }

        int size()   { return entries.size(); }
        auto begin() { return entries.begin(); }
        auto end()   { return entries.end(); }
        auto begin() const { return entries.begin(); }
        auto end()   const { return entries.end(); }
    };

    // ------------- CLASS MEMBERS ------------------------------

    int count = 0;             // number of entries
    int table_size = 29;       // number of buckets

    int hash(Key k) const { return ((21 * k) + 4); } 
    int hash(Key k) { return ((21 * k) + 4); } 
    std::vector<Bucket> table;

    // ------------- CLASS FUNCTIONS ------------------------------

    int get_index(const Key& key) const {return hash(static_cast<int>(key)) % table_size; }
    int get_index(const Key& key) {return hash(static_cast<int>(key)) % table_size; }

    void clear() {
        for (Bucket b : table) {
            b.clear();
        }
        count = 0;
    }

    void resize(int new_table_size) 
    {
        std::vector<Entry> buffer;
        for (Bucket b : table) 
        {
            for (Entry e : b ) {
                buffer.push_back(e);
            }
            table_size = new_table_size;
            count = 0;

            // something needs to happen here just dont know what

            for (Entry e: buffer) {
                table.put(e.key(), e.value());
            }
        }
        
    }

    void create_table() 
    {
        table.clear();
        table.resize(table_size);
    }

public:

    Hashmap() { create_table(); }

    const auto find(const Key& k) const 
    {
        const Bucket& bucket = table[get_index(k)];
        auto pos = bucket.find(k);
        if (pos == bucket.end()) {
            return bucket.end();
        } else {
            return pos;
        }
    }

    const Value& get(const Key& k) const {
        return find(k)->value();
    }

    Value& get(Key& k) {
        Bucket& bucket = table[get_index(k)];
        auto pos = bucket.find(k);
            if (pos == bucket.end()) {
                return bucket.end();
            } else {
                return pos->value();
            }
        }


    auto put(const Key& k, const Value& v) 
    {
        int old_size = table[k].size();
        Bucket& bucket = table[get_index(k)];
        if (bucket.put(k,v)) {
           count += (table[k].size() - old_size);
        }
        return bucket.find(k);
    }
    
    bool erase(const Key& k) 
    {
        Bucket& bucket = table[get_index(k)];
        if (bucket.erase(k)) {
            count--;
            return true;
        } else {
            return false;
        }
    }

    int get_count() {
        return count;
    }

    int get_table_size() {
        return table_size;
    }

};

#endif
