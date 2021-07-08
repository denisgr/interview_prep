#pragma once
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
   std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
      std::unordered_map<int, std::vector<int>> indexes;
      std::vector<std::vector<int>> result;
      // n * log n
      std::sort(nums.begin(), nums.end());

      // n
      for (int i = 0 ; i < nums.size(); ++i)
      {
         auto& v = indexes[nums[i]];
         v.push_back(i);
      }

      for (int i = 0; i < nums.size(); ++i)
      {
         for (int k = i + 1; k < nums.size(); ++k)
         {
            auto iter = indexes.find(nums[i] + nums[k]);
            if (iter != indexes.end())
            {
               int index = -1;
               for (int j = 0; j < iter->second.size(); ++j)
               {
                  if (iter->second[j] > k)
                  {
                     index = iter->second[j];
                     break;
                  }
               }
               if (index != -1)
                  result.push_back({ nums[i], nums[k], nums[index] });
            }
            while (k < nums.size() - 1 && nums[k + 1] == nums[k])
               k++;
         }
         while (i < nums.size() - 1 && nums[i + 1] == nums[i])
            i++;
      }
      return result;
   }
};
