#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <vector>

#ifndef FILE_PARSER_CLASS
#define FILE_PARSER_CLASS

class FileParser
{
public:

    FileParser() {}

    std::string convertFileToString(std::string filePath) 
    {
        std::ifstream book1(filePath);
        std::stringstream buffer1;
        buffer1 << book1.rdbuf();
        return buffer1.str();    
    }

    std::vector<std::string> splitUpString(std::string s) 
    {
        std::vector<std::string> result;
        std::string temp = {};
        for (int i = 0; i < s.size(); i++) {
            if (std::isalnum(s[i])) {
                temp += (s[i]);
            }
            
            if (!std::isalnum(s[i + 1])) {
                result.push_back(temp);
                temp.clear();
                continue;
            }
        }
        return result;
    }
    
};

#endif