#pragma once
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
   std::vector<std::string> letterCombinations(std::string digits) {
      std::unordered_map<char, std::string> d = { {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"} };

      std::vector<std::string> result;

      generateCombinations(d, result, digits);
      return result;
   }

   void generateCombinations(std::unordered_map<char, std::string>& d, std::vector<std::string>& res, std::string s)
   {
      if (s.empty())
      {
         return;
      }
      std::string& letters = d[s.front()];
      if (res.empty())
      {
         for (auto l : letters)
         {
            std::string c;
            c.push_back(l);
            res.push_back(c);
         }
         generateCombinations(d, res, s.substr(1));
         return;
      }

      std::vector<std::string> new_res;
      for (auto new_s : res)
      {
         for (auto l : letters)
         {
            std::string c(new_s);
            c.push_back(l);
            new_res.push_back(c);
         }
      }
      res.swap(new_res);
      generateCombinations(d, res, s.substr(1));
   }

};
