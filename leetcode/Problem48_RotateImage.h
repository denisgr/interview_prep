#pragma once

#include <vector>

class Solution {
public:
   void rotate(std::vector<std::vector<int>>& matrix) {
      int offset = 0;
      int sideLength = matrix.size();
      while (sideLength > 1)
      {
         for (int i = 0; i < sideLength - 1; ++i)
         {
            int temp = matrix[offset][i + offset];
            matrix[offset][offset + i] = matrix[offset + sideLength - i - 1][offset];
            matrix[offset + sideLength - i - 1][offset] = matrix[offset + sideLength - 1][offset + sideLength - i - 1];
            matrix[offset + sideLength - 1][offset + sideLength - i - 1] = matrix[offset + i][offset + sideLength - 1];
            matrix[offset + i][offset + sideLength - 1] = temp;
         }
         sideLength-=2;
         offset++;
      }
   }
};