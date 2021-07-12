#pragma once

#include <vector>

class Solution {

   int factorial(int n)
   {
      if (n == 0 || n == 1)
         return 1;
      else
         return n * factorial(n - 1);
   }

   void generatePermutations(std::vector<int> nums, std::vector<std::vector<int>>& res, std::vector<int> permutation)
   {
      for (int i = 0; i < nums.size(); ++i)
      {
         auto new_nums(nums);
         new_nums.erase(new_nums.begin() + i);
         int f = factorial(new_nums.size());
         auto perm_copy(permutation);
         perm_copy.push_back(nums[i]);
         if (nums.size() == 1)
            res.push_back(perm_copy);
         else
            generatePermutations(new_nums, res, perm_copy);
      }
   }
public:
   std::vector<std::vector<int>> permute(std::vector<int>& nums) {
      std::vector<std::vector<int>> res;
      generatePermutations(nums, res, std::vector<int>());
      return res;
   }
};