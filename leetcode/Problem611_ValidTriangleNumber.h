#pragma once

#include <vector>
#include <algorithm>

class Solution {
public:
   int triangleNumber(std::vector<int>& nums) {
      if (nums.size() < 3)
         return 0;
      int res = 0;
      std::sort(nums.begin(), nums.end());
      for (int i = 0; i < nums.size() - 2; ++i)
      {
         int l = i + 1;
         int r = i + 2;
         while (r < nums.size())
         {
            auto iter = std::lower_bound(nums.begin() + r, nums.end(), nums[i] + nums[l]);
            res += std::distance(nums.begin() + r, iter);
            l++;
            r = l + 1;
         }
      }
      return res;
   }
};