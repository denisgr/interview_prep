#pragma once

#include <vector>

class Solution {
public:
   int climbStairs(int n) {
      using namespace std;
      vector<int> amountOfOptions(n, 0);
      amountOfOptions[0] = 1;
      if (n > 1)
         amountOfOptions[1] = 2;
      for (int i = 2; i < n; ++i)
      {
         amountOfOptions[i] = amountOfOptions[i - 1] + amountOfOptions[i - 2];
      }
      return amountOfOptions.back();
   }
};