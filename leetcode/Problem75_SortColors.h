#pragma once
#include <vector>
class Solution {
public:
   void sortColors(std::vector<int>& nums) {
      for (int i = 0; i < nums.size(); ++i)
      {
         for (int k = i; k < nums.size(); ++k)
         {
            if (nums[k] < nums[i])
            {
               std::swap(nums[k], nums[i]);
            }
         }
      }
   }
};