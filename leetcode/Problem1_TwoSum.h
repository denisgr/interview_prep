#pragma once

#include <vector>
#include <unordered_map>

using std::vector;

class Solution {
public:
   vector<int> twoSum(vector<int>& nums, int target) {
      using namespace std;
      unordered_map<int, vector<int>> n;
      int index = 0;
      for (auto && num : nums)
      {
         auto& indexes = n[num];
         indexes.push_back(index);
         index++;
      }

      for (auto && number : n)
      {
         int rem = target - number.first;
         if (rem == number.first)
         {
            return { static_cast<int>(number.second[0]), static_cast<int>(number.second[1]) };
         }
         auto iter = n.find(rem);
         if (iter != n.end())
         {
            return { number.second[0], iter->second[0] };
         }
      }

      return {};
   }
};