#include <iostream>
#include <fstream>
#include "file_indexer.hpp"

#ifndef FILE_WRITER_CLASS
#define FILE_WRITIER_CLASS

class FileWriter 
{
public:
    FileWriter() {}

    void outputToFile(FileIndexer& f, std::string fileName) 
    {
        std::ofstream outFile;
        outFile.open(fileName);

        while (!outFile) {
           outFile.close();
           outFile.clear(); 
        }

        outFile << f;
    }
};


#endif
