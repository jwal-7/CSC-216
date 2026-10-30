#include <iostream>
#include <map>
#include <vector>

#ifndef FILE_INDEX_MAP_CLASS
#define FILE_INDEX_MAP_CLASS

class FileIndexMap
{
private:
    std::map<std::string, std::vector<size_t>> table;

public:
    FileIndexMap() : table() {}

    void insert(std::string k, size_t v) 
    {
        
    }


    
};


#endif