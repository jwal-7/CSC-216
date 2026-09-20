#include "array_sorts.hpp"
#include <iostream>
#include <cmath>
#include <vector>


std::vector<int> naiveShuffle(std::vector<int> vec) 
{
   const int length = vec.size();
   std::vector<int> shuffled;
   shuffled.reserve(length);
   std::vector<bool> used(length, false);
   int n = length, i;

   while (n) {
      i = (rand() % length);
      
      if (!used[i]) { // if element has not been used/shuffled
         shuffled.push_back(vec[i]);
         used[i] = true;
         n--;
      }
   }
   return shuffled;
}

std::vector<int> partlyOptimizedShuffle(std::vector<int> vec) 
{
   std::vector<int> shuffled;
   shuffled.reserve(vec.size());
   int n = vec.size(), i;
   
   while (n) {
      i = (rand() % n--);
      shuffled.push_back(vec[i]);
      vec.erase(vec.begin() + i);
   }
   return shuffled;
}

std::vector<int>& optimizedShuffle(std::vector<int>& vec) 
{
   int m = vec.size(), t , i;

   while (m) {
      i = (rand() % m--);

      t = vec[m];
      vec[m] = vec[i];
      vec[i] = t;
   }
   return vec;
}

