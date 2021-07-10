#pragma once

#include <string>
#include <sstream>

class Solution {
public:
   std::string convert(std::string s, int numRows) {
      if (numRows == 1)
         return s;
      std::ostringstream oss;
      for (int i = 0; i < numRows; ++i)
      {
         int index = 0;
         while (2 * index * (numRows - 1) + i < s.size())
         {
            if (i == 0 || i == numRows - 1) // first and last row
            {
               oss << s[2 * index * (numRows - 1) + i];
            }
            else
            {
               oss << s[2 * index * (numRows - 1) + i];
               if (2 * (numRows - 1) * (index + 1) - i < s.size())
                  oss << s[2 * (numRows - 1) * (index + 1) - i];
            }
            index++;
         }
      }
      return oss.str();
   }
};