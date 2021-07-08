#pragma once
#include <string>

class Solution {
   bool isPalindrome(const std::string& s, int off, int count)
   {
      int begin = off;
      int end = off + count-1;
      while (begin <= end)
      {
         if (s[begin] != s[end])
            return false;
         begin++;
         end--;
      }
      return true;
   }
public:
   std::string longestPalindrome(std::string s) {
      if (s.empty())
         return std::string();

      for (int i = 0; i < s.size(); ++i)
      {
         for (int k = 0; k < i + 1; ++k)
         {
            if (isPalindrome(s, k, s.size() - i))
               return s.substr(k, s.size() - i);
         }
      }
      return s;
   }
};
