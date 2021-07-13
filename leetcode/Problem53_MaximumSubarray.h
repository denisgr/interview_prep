#pragma once
#include <vector>
class Solution {
public:
   int maxSubArray(std::vector<int>& nums) {
      using namespace std;
      vector<int> subSums;
      subSums.push_back(nums[0]);
      int max = nums[0];
      for (int i = 1; i < nums.size(); ++i)
      {
         subSums.push_back(std::max(subSums[i - 1] + nums[i], nums[i]));
         max = std::max(max, subSums[i]);
      }
      return max;
   }
};