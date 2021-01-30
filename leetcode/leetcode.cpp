#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
   int lengthOfLongestSubstring(string s) {
      unordered_set<char> unique_chars;
      size_t result = 0;
      for (size_t i = 0; i < s.size(); ++i)
      {
         unique_chars.clear();
         for (size_t n = 0; n < s.size() - i; ++n)
         {
            if (unique_chars.find(s[n + i]) != unique_chars.end())
            {
               break;
            }
            unique_chars.insert(s[n + i]);
            result = max(result, unique_chars.size());
         }
      }
      return static_cast<int>(result);
   }
};

int main()
{

}