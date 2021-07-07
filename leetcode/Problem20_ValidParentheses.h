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

         if (openedP.empty() ||
             c == ']' && openedP.back() != '[' ||
             c == ')' && openedP.back() != '(' ||
             c == '}' && openedP.back() != '{')
         {
            return false;
         }
         openedP.pop_back();
      }

      return openedP.empty();
   }
};
