#pragma once

#include <vector>
#include <algorithm>

class Solution {
public:
   std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
      using namespace std;
      std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& lhs, const std::vector<int>& rhs) { return lhs.front() < rhs.front(); });
      vector<vector<int>> result;
      vector<int> currentInterval;
      for (int i = 0; i < intervals.size(); ++i)
      {
         if (currentInterval.empty())
         {
            currentInterval = intervals[i];
         }
         else if (currentInterval[1] >= intervals[i][0])
         {
            currentInterval[1] = max(currentInterval[1], intervals[i][1]);
         }
         else
         {
            result.push_back(currentInterval);
            currentInterval = intervals[i];
         }

         if (i == intervals.size() - 1)
            result.push_back(currentInterval);
      }
      return result;
   }
};