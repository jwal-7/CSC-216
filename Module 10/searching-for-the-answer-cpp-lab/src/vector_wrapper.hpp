#include <vector>
#include <iostream>

#ifndef VECTOR_WRAPPER_CLASS
#define VECTOR_WRAPPER_CLASS

template<typename T>
class IndexList 
{
public:
    std::vector<T> v;

    IndexList() {}
};

template<typename T>
std::ostream& operator<<(std::ostream& outs, const IndexList<T>& list) {
    outs << "[";
    if (!list.v.empty()) {
        outs << list.v.front();
        for (size_t i = 1; i < list.v.size(); ++i) {
            outs << ", " << list.v[i];
        }
    }
    outs << "]";
    return outs;
}


#endif
