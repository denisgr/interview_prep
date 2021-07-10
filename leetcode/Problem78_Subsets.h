#pragma once

#include <vector>
#include <cmath>

class Solution {
public:
   std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
      std::vector<std::vector<int>> res;

      int p = std::pow(2, nums.size());

      for (int i = 0; i < p; ++i)
      {
         std::vector<int> element;
         for (int j = 0; j < nums.size(); ++j)
         {
            int lastDigit = (i >> j) & 1;
            if (lastDigit)
            {
               element.push_back(nums[j]);
            }
         }
         res.push_back(element);
      }
      return res;
   }
};