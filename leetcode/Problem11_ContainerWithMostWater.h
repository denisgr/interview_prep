#pragma once
#include <vector>

class Solution {
public:
   int maxArea(std::vector<int>& height) {
      using namespace std;
      int left = 0, right = height.size() - 1;
      int area = 0;
      while (left < right)
      {
         area = max(area, min(height[right], height[left]) * (right - left));
         if (height[left] < height[right])
         {
            left++;
         }
         else
         {
            right--;
         }
      }
      return area;
   }
};
