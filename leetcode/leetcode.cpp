#include <iostream>
#include <string>
#include <unordered_set>
#include <sstream>
using namespace std;

class Solution {
public:
   int myAtoi(string s) {
      size_t i = 0;
      bool isNegative = false;
      while (true)
      {
         if (s[i] == ' ')
         {
            ++i;
         }
         else if (s[i] == '+')
         {
            ++i;
            break;
         }
         else if (s[i] == '-')
         {
            ++i;
            isNegative = true;
            break;
         }
         else if (s[i] >= '0' && s[i] <= '9')
         {
            break;
         }
         else
            return 0;
      }

      string lowest("2147483648"), highest("2147483647");
      string oss;
      while (i < s.size() && s[i] == '0')
         ++i;
      while (i < s.size() && s[i] >= '0' && s[i] <= '9')
      {
         oss += s[i];
         ++i;
      }

      if (isNegative && (oss.size() > lowest.size() || (oss.size() == lowest.size() && oss > lowest)))
         return -2147483648;
      if (!isNegative && (oss.size() > highest.size() || (oss.size() == highest.size() && oss > highest)))
         return 2147483647;

      long long result = 0;
      for (i = 0; i < oss.size(); ++i)
      {
         result = result * 10 + (oss[i] - '0');
      }
      return isNegative ? result * -1 : result;
   }
};

int main()
{

}