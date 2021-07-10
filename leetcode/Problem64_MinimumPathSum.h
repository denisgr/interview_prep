#pragma once

#include <vector>

class Solution {
public:
   int minPathSum(std::vector<std::vector<int>>& grid) {
      std::vector<std::vector<int>> minimumPathSums(grid.size());
      for (int i = 0; i < grid.size(); ++i)
      {
         minimumPathSums[i] = std::vector<int>(grid[i].size());
      }
      minimumPathSums[0][0] = grid[0][0];

      for (int i = 0; i < grid.size(); i++)
      {
         for (int j = 0; j < grid[i].size(); ++j)
         {
            if (i == 0 && j == 0)
               continue;
            int prevIVal = i > 0 ? minimumPathSums[i - 1][j] : 200;
            int prevJVal = j > 0 ? minimumPathSums[i][j - 1] : 200;
            minimumPathSums[i][j] = grid[i][j] + std::min(prevIVal, prevJVal);
         }
      }
      return minimumPathSums.back().back();
   }
};