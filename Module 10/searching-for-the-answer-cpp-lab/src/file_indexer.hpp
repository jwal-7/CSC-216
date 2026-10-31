#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include "file_index_map.hpp"

#ifndef FILE_INDEXER_CLASS
#define FILE_INDEXER_CLASS

class FileIndexer 
{
private:
    FileIndexMap fileIndex;

    std::unordered_map<std::string, int> wordsToAvoid = 
     {{"a", 1}, {"and", 1}, {"the", 1}, {"they", 1}, {"to", 1}, {"for", 1},
      {"they", 1}, {"you", 1}, {"your", 1}, {"be", 1}, {"of", 1}, {"in", 1}, 
      {"that", 1}, {"have", 1}, {"I", 1}, {"it", 1}, {"not", 1}, {"on", 1}, 
      {"with", 1}, {"he", 1}, {"as", 1}, {"do", 1}, {"at", 1}, {"this", 1}, 
      {"but", 1}, {"his", 1}, {"by", 1}, {"from", 1}, {"is", 1} }; // dummy value to act as set without implementing it or using std::unordered_set
      // hashmap over vector to get O(1) lookups instead of O(n)


    bool isCommonWord(std::string input) {
        if (wordsToAvoid.contains(input)) {
           return true;
        }
        return false;
    }

public:

    void makeIndex(std::vector<std::string> s) 
    {
        for (size_t i = 0; i < s.size(); i++) {
            if (!isCommonWord(s[i]) && s[i] != "") {
                fileIndex.insert(s[i], i);
            }
        }
    }

    void print(std::ostream& outs) const {
        fileIndex.print(outs);
    }
    
};

std::ostream& operator<<(std::ostream& outs, const FileIndexer& indexer) {
    indexer.print(outs);
    return outs;
} 

#endif
