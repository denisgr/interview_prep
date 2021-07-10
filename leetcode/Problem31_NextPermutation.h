#pragma once

#include <vector>
#include <algorithm>

class Solution {
public:
   void nextPermutation(std::vector<int>& nums) {
      for (int i = nums.size() - 1; i > 0 ; --i)
      {
         int rhs = i;
         int lhs = i - 1;
         if (nums[lhs] < nums[rhs])
         {
            for (int j = rhs; j < nums.size(); ++j)
            {
               if (nums[j] > nums[lhs] && nums[j] < nums[rhs])
                  std::swap(nums[rhs], nums[j]);
            }
            std::swap(nums[rhs], nums[lhs]);
            std::sort(nums.begin() + rhs, nums.end());
            return;
         }
      }
      std::sort(nums.begin(), nums.end());
   }
};