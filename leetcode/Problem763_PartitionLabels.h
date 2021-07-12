#pragma once

#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
   std::vector<int> partitionLabels(std::string s) {
      using namespace std;
      std::unordered_map<char, std::pair<int, int>> leftAndRightIndex;
      for (int i = 0; i < s.size(); ++i)
      {
         auto r = leftAndRightIndex.insert(std::make_pair(s[i], std::make_pair(i, i)));
         if (!r.second)
         {
            r.first->second.second = i;
         }
      }

      int index = 0;
      auto p = leftAndRightIndex[s[index]];
      vector<int> res;
      while (index <= s.size() - 1)
      {
         int min = p.first;
         int max = p.second;
         for (int i = min; i < max; ++i)
         {
            max = std::max(max, leftAndRightIndex[s[i]].second);
         }
         res.push_back(max - min + 1);
         index = max + 1;
         p = leftAndRightIndex[s[index]];
      }
      return res;
   }
};