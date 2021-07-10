#pragma once
#include <vector>
#include <unordered_set>

class Solution {
public:
   std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
      std::unordered_set<int> candidates_(candidates.begin(), candidates.end());
      std::vector<std::vector<int>> result;
      std::vector<int> currentComb;
      generateCombinations(result, candidates_, currentComb, 1, 0, target);
      return result;
   }

   void generateCombinations(std::vector<std::vector<int>>& res, const std::unordered_set<int>& candidates, std::vector<int>& currentComb, int startNumber, int sum, int target)
   {
      if (target == 0)
      {

         res.push_back(currentComb);
         return;
      }
      else if (target < 0)
      {
         return;
      }
      else
      {
         for (int i = startNumber; i <= target; ++i)
         {
            if (candidates.find(i) != candidates.end())
            {
               currentComb.push_back(i);
               generateCombinations(res, candidates, currentComb, i, sum + i, target - i);
               currentComb.pop_back();
            }
         }
      }
   }
};