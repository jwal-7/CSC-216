#include <iostream>
#include <map>
#include <vector>
#include "vector_wrapper.hpp"

#ifndef FILE_INDEX_MAP_CLASS
#define FILE_INDEX_MAP_CLASS

class FileIndexMap
{
private:
    std::map<std::string, IndexList<size_t>> table;

public:
    FileIndexMap() : table() {}

    void insert(std::string k, size_t v) 
    {
       table[k].v.push_back(v);
    }

    int size() {
        return table.size();
    }
    
    void print(std::ostream& outs) const {
        outs << "{\n";

        for (auto it = table.begin(); it != table.end(); ++it) {
            outs << "    \"" << it->first << "\": "  << it->second << "\n";
        }

        outs << "}\n";
    }
    
};

std::ostream& operator<<(std::ostream& outs, const FileIndexMap& map) {
    map.print(outs);
    return outs;
} 


#endif
