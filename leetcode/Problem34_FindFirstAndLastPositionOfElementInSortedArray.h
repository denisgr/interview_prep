#pragma once

#include <vector>
#include <algorithm>

class Solution {
public:
   std::vector<int> searchRange(std::vector<int>& nums, int target) {
      auto l = std::lower_bound(nums.begin(), nums.end(), target);
      if (l != nums.end() && *l == target)
      {
         auto r = std::upper_bound(l, nums.end(), target);
         return { static_cast<int>(std::distance(nums.begin(), l)), r == nums.end() ? static_cast<int>(nums.size() - 1) : static_cast<int>(std::distance(nums.begin(), r) - 1) };
      }
      return { -1, -1 };
   }
};