#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>
#include <iostream>

class Solution {
   std::string encode(const std::string& s)
   {
      using namespace std;
      unordered_map<char, int> hist;
      for (auto c : s)
      {
         int& v = hist[c];
         v++;
      }
      ostringstream oss;
      for (char c = 'a'; c <= 'z'; c++)
      {
         auto iter = hist.find(c);
         if (iter != hist.end())
         {
            oss << c << iter->second;
         }
      }
      return oss.str();
   }
public:
   std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
      using namespace std;
      unordered_map<string, vector<string>> groupByAnagram;
      for (const auto& s : strs)
      {
         auto anagram = encode(s);
         auto& v = groupByAnagram[anagram];
         v.push_back(s);
      }
      vector<vector<string>> res;
      for (const auto& s : groupByAnagram)
      {
         res.push_back(s.second);
      }
      return res;
   }
};