#include <iostream>
#include "hashmap.hpp"

class ComparisonHashmap 
{
public:

    ComparisonHashmap() {}

    bool can_create_note(std::string note, std::string articles)
    {   
        Hashmap<char,int> articles_map;
        

        for(char c: articles) {
            if (isgraph(c)) {
                articles_map[tolower(c)] += 1;
            }
        }

        for(char c : note) {
             if (isgraph(c)) {
                int key = tolower(c);
                if (!articles_map.contains(key)) { // letter never existed
                    return false;
                } if (articles_map[key] == 0) { // letter all used up
                    return false;
                }
                articles_map[key] -= 1; // uses a letter each time it passes
            }
        }
        return true;
       
    }
};
