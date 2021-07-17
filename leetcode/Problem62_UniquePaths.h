#pragma once

#include <vector>

class Solution {
public:
   int uniquePaths(int m, int n) {
      using namespace std;
      vector<vector<int>> paths(m, vector<int>(n, 0));
      paths[0][0] = 1;
      for (int i = 0; i < m; ++i)
      {
         for (int k = 0; k < n; ++k)
         {
            if (k == 0 && i == 0)
            {
               paths[i][k] = 0;
            }
            else if (k != 0 && i == 0)
            {
               paths[i][k] = paths[i][k - 1];
            }
            else if (k == 0 && i != 0)
            {
               paths[i][k] = paths[i - 1][k];
            }
            else
            {
               paths[i][k] = paths[i - 1][k] + paths[i][k - 1];
            }
         }
      }
      return paths.back().back();
   }
};