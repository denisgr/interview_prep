#pragma once
#include <string>
#include <unordered_set>

class Solution {
public:
   int lengthOfLongestSubstring(std::string s) {
      using namespace std;
      unordered_set<char> uniqueChars;
      int longestString = 0;
      for (char& i : s)
      {
         if (uniqueChars.count(i) == 0)
         {
            uniqueChars.insert(i);
         }
         else
         {
            longestString = max(static_cast<int>(uniqueChars.size()), longestString);
            uniqueChars.clear();
         }
      }
      return longestString;
   }
};
