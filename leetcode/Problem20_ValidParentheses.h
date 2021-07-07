#pragma once
#include <string>
#include <vector>
class Solution {
public:
   bool isValid(std::string s) {
      using namespace std;
      vector<char> openedP;

      for (auto c : s)
      {
         if (c == '(' || c == '[' || c == '{')
         {
            openedP.push_back(c);
            continue;
         }

         if (c == ']' && openedP.back() != '[' ||
             c == ')' && openedP.back() != '(' ||
             c == '}' && openedP.back() != '{' ||
             openedP.empty())
         {
            return false;
         }
         openedP.pop_back();
      }

      return openedP.empty();
   }
};
