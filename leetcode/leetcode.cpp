#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <unordered_set>
#include <sstream>
#include <unordered_map>
using namespace std;


class Solution {
public:
   int maxArea(vector<int>& height) {
      int l = 0, h = static_cast<int>(height.size()) - 1;

      int square = min(height[l], height[h]) * (h - l);

      while (l < h)
      {
         if (height[l] < height[h])
         {
            l++;
         }
         else
            h--;
         square = max(square, (h - l) * min(height[l], height[h]));
      }

      return square;
   }
};

int main()
{
}