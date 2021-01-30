#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
   string longestPalindrome(string s) {

      for (size_t l = s.size(); l > 0; --l)
      {
         for (size_t k = 0; k < s.size() - l; ++k)
         {
            if (isPalindrome(k, l + k, s))
            {
               return s.substr(k, l);
            }
         }
      }
      return "";
   }

   static bool isPalindrome(size_t l, size_t r, const string& s)
   {
      while(l < r)
      {
         if (s[l] != s[r])
            return false;
         l++; r--;
      }
      return true;
   }
};

int main()
{

}