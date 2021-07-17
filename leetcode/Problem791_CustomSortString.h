#pragma once

#include <string>
#include <algorithm>

class Solution {
public:
   std::string customSortString(std::string order, std::string str) {
      char arr[26] = { 0 };
      for (int i = 0; i < order.size(); ++i)
      {
         arr[order[i] - 'a'] = i;
      }
      std::sort(str.begin(), str.end(), [&arr](char l, char r)
         {
            auto lOrder = arr[l - 'a'];
            auto rOrder = arr[r - 'a'];
            return lOrder < rOrder;
         });
      return str;
   }
};