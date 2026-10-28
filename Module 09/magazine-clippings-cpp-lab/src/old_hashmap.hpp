#include <unordered_map>
#include <iostream>

class ComparisonHashmap 
{
private:

    std::unordered_map<char, int>root_map;

    std::unordered_map<char, int>compare_map;
public:

    ComparisonHashmap() : root_map{}, compare_map{} {}

    bool can_create_note(std::string note, std::string articles)
    {   
        root_map.clear(); // makes sure nothing carries over from any previous calls
        compare_map.clear();

        for(char c: articles) {
            if (isgraph(c)) {
                compare_map[tolower(c)]++;
            }
        }

        for(char c : note) {
             if (isgraph(c)) {
                root_map[tolower(c)]++;
            }
        }

       for (auto it = root_map.begin(); it != root_map.end(); ++it) {
            if (it->second > compare_map[it->first]) {
                return false;
            }
       }
       return true;
    }
};
