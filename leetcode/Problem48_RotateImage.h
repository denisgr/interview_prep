#pragma once

#include <vector>

class Solution {
public:
   void rotate(std::vector<std::vector<int>>& matrix) {
      int offset = 0;
      int sideLength = matrix.size() - 1;
      while (sideLength > 1)
      {
         for (int i = offset; i < sideLength; ++i)
         {
            int temp = matrix[offset][i];
            matrix[offset][i] = matrix[sideLength - i][offset];
            matrix[sideLength - i][offset] = matrix[sideLength - i][sideLength - i];
            matrix[sideLength - i] [sideLength - i] = matrix[offset][sideLength - i];
            matrix[offset][sideLength - i] = temp;
         }
      }
   }
};