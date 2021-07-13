#pragma once

#include <vector>

class Solution {
public:
   bool canJump(std::vector<int>& nums) {
      int stairs = nums[0];
      int max = 0;
      for (int i = 0; i < nums.size(); ++i)
      {
         if (stairs == 0)
         {
            stairs += std::max(max, nums[i]);
            if (stairs == 0)
               return false;
         }

         max = std::max(max, nums[i]);
         stairs--;
         max -= 1;
      }
      return true;
   }
};