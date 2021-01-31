#include <iostream>
#include <string>
#include <unordered_set>
#include <sstream>
using namespace std;

class Solution {
public:
   string convert(string s, int numRows) {
      ostringstream oss;
      for (size_t i = 0; i < numRows; ++i)
      {
         int rowNumber = 0;
         int increment = numRows != 1 ? 1 : 0;
         size_t k = 0;
         while (k < s.size())
         {
            if (numRows != 1 && rowNumber == numRows - 1)
            {
               increment = -1;
            }
            else if (numRows != 1 && rowNumber == 0)
               increment = 1;
            if (rowNumber == i)
            {
               oss << s[k];
            }
            rowNumber += increment;
            ++k;
         }
      }
      return oss.str();
   }
};

int main()
{

}