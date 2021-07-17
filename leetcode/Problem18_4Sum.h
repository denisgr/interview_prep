#pragma once
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
class Solution {

public:
   std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {

      using namespace std;
      unordered_map<int, vector<pair<pair<int,int>, pair<int,int>>>> pairs;
      for (int i = 0; i < nums.size(); ++i)
      {
         for (int k = i + 1; k < nums.size(); ++k)
         {
            auto& v = pairs[nums[i] + nums[k]];
            v.push_back(make_pair(make_pair(i, nums[i]), make_pair(k, nums[k])));
         }
      }

      set<vector<int>> res;
      set<int> used_nums;
      for (const auto& p : pairs)
      {
         if (used_nums.find(p.first) != used_nums.end())
            continue;
         auto iter = pairs.find(target - p.first);
         if (iter != pairs.end())
         {
            for (const auto& f : p.second)
            {
               for (const auto& s : iter->second)
               {
                  if (f.first.first != s.first.first && f.first.first != s.second.first &&
                     f.second.first != s.first.first && f.second.first != s.second.first)
                  {
                     vector<int> vv{ f.first.second, f.second.second, s.first.second, s.second.second };
                     std::sort(vv.begin(), vv.end());
                     res.insert(vv);
                  }
               }
            }
            used_nums.insert(p.first);
            used_nums.insert(iter->first);
         }
      }
      vector<vector<int>> result(res.begin(), res.end());
      return result;
   }
};