#pragma once
#include <vector>

class Solution {
public:
   int search(std::vector<int>& nums, int target) {
      int pivotPoint = findIndex(nums, 0, nums.size() - 1);

      auto iter = std::lower_bound(nums.begin(), nums.begin() + pivotPoint, target);
      if (target >= nums[0] && target <= nums[pivotPoint > 0 ? pivotPoint - 1 : pivotPoint] && iter != nums.end() && *iter == target)
         return std::distance(nums.begin(), iter);
      iter = std::lower_bound(nums.begin() + pivotPoint, nums.end(), target);
      if (target >= nums[pivotPoint] && target <= nums.back() && iter != nums.end() && *iter == target)
         return std::distance(nums.begin(), iter);
      return -1;
   }

   int findIndex(const std::vector<int>& nums, int beg, int end)
   {
      if (end - beg <= 1)
      {
         return end;
      }
      int middle = (beg + end) / 2;
      if (nums[middle] < nums[beg])
      {
         return findIndex(nums, beg, middle);
      }
      else
      {
         return findIndex(nums, middle, end);
      }
   }
};