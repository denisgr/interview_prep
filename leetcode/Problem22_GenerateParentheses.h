#pragma once
#include <vector>
#include <string>

class Solution {
public:
   std::vector<std::string> generateParenthesis(int n) {
      std::vector<std::string> res;
      generateCombination(n * 2, n, n, std::string(), 0, res);
      return res;
   }

   void generateCombination(int level, int l, int r, std::string base, int bal, std::vector<std::string>& res)
   {
      if (level == 0)
      {
         res.push_back(base);
         return;
      }

      if (l)
      {
         std::string new_base(base);
         new_base.push_back('(');
         generateCombination(level - 1, l - 1, r, new_base, bal + 1, res);
      }

      if (r && bal > 0)
      {
         std::string new_base(base);
         new_base.push_back(')');
         generateCombination(level - 1, l, r - 1, new_base, bal - 1, res);
      }
   }
};