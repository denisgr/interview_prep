#pragma once

#include <vector>

class Solution {
public:
   int jump(std::vector<int>& nums) {
      using namespace std;
      vector<int> jumpsCount(nums.size(), 1000000);
      jumpsCount[0] = 0;
      for (int i = 0; i < nums.size(); ++i)
      {
         for (int k = 0; k <= nums[i]; ++k)
         {
            if (i + k < nums.size())
               jumpsCount[i + k] = std::min(jumpsCount[i + k], jumpsCount[i] + 1);
         }
      }
      return jumpsCount.back();
   }
};