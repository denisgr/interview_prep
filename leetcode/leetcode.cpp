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
   vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int, vector<int>> nums_with_indexes;
      for (size_t i = 0; i < nums.size(); ++i)
      {
         auto& v = nums_with_indexes[target - nums[i]];
         v.push_back(i);
      }

      for (int i = 0; i < nums.size(); ++i)
      {
         auto iter = nums_with_indexes.find(nums[i]);
         if (iter != nums_with_indexes.end())
         {
            auto& v = iter->second;
            for (int k = 0; k < v.size(); ++k)
            {
               if (v[k] != i)
               {
                  return { i,v[k] };
               }
            }
         }
      }
      return {};
   }
};

int main()
{
   vector<int> v{ 3,2,4 };
   Solution s;
   s.twoSum(v, 6);
}