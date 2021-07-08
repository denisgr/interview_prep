#pragma once
#include <string>
#include <unordered_set>

class Solution {
public:
   int lengthOfLongestSubstring(std::string s) {
      using namespace std;
      unordered_set<char> uniqueChars;
      int begin = 0, end = 0, longestSubstring = 0;
      while (end != s.size() - 1)
      {
         if (uniqueChars.count(s[end]) == 0)
         {
            uniqueChars.insert(s[end]);
            end++;
         }
         else
         {
            uniqueChars.erase(s[begin]);
            begin++;
         }
         longestSubstring = max(end - begin, longestSubstring);
      }
      return longestSubstring;
   }
};
