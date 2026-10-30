#include <iostream>
#include <map>
#include <vector>

#ifndef FILE_INDEXER_CLASS
#define FILE_INDEXER_CLASS

class FileIndexer 
{
private:
    static std::map<std::string, size_t> fileIndex;

    std::vector<std::string> wordsToAvoid =
     {"a", "and", "the", "they", "to", "for", "they", "you", "your"
      "be", "of", "in", "that", "have", "I", "it", "not", "on", "with"
      "he", "as", "do", "at", "this", "but", "his", "by", "from",};

    void makeIndex(std::vector<std::string> s) 
    {
        
    }
};

#endif