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
   vector<vector<int>> threeSum(vector<int>& nums) {
      vector<int> nums_uniq;
      sort(nums_uniq.begin(), nums_uniq.end());
      nums_uniq.erase(unique(nums_uniq.begin(), nums_uniq.end()), nums_uniq.end());
      if (nums_uniq.size() == 1 && nums.size() > 3)
      {
         vector<int> r{ nums_uniq[0],nums_uniq[0],nums_uniq[0] };
         return { r };
      }

      unordered_map<int, vector<int>> nums_indexes;
      for (size_t i = 0; i < nums.size(); ++i)
      {
         auto& v = nums_indexes[nums[i]];
         v.push_back(i);
      }
      set<vector<int>> res;
      set<pair<int, int>> present_pairs;
      for (size_t i = 0; i < nums.size(); ++i)
      {
         for (size_t n = i + 1; n < nums.size(); ++n)
         {
            if (present_pairs.find(make_pair(nums[i], nums[n])) != present_pairs.end())
               continue;
            present_pairs.insert(make_pair(nums[i], nums[n]));
            auto iter = nums_indexes.find(0 - (nums[i] + nums[n]));
            if (iter != nums_indexes.end())
            {
               auto& v = iter->second;
               for (size_t l = 0; l < v.size(); ++l)
               {
                  if (v[l] > n)
                  {
                     vector<int> r{ nums[i], nums[n], nums[v[l]] };
                     sort(r.begin(), r.end());
                     res.insert(r);
                  }
               }
            }
         }
      }
      return vector<vector<int>>(res.begin(), res.end());
   }
};

int main()
{
   vector<int> t{ -4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6 };
   Solution s;
   s.threeSum(t);
}