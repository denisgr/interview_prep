#include <iostream>
#include <string>
#include <unordered_set>
#include <sstream>
#include <unordered_map>
using namespace std;

class Solution {
public:
   vector<string> letterCombinations(string digits) {
      unordered_map<char, string> digitToLettersMapping = { {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"} };

      vector<string> res;
      if (digits.empty())
         return res;
      getCombination(digitToLettersMapping, 0, digits, string(), res);
      return res;
   }

   void getCombination(const unordered_map<char, string>& m, size_t index, const string& digits, string word, vector<string>& result)
   {
      const auto c = digits[index];
      const auto& letters = m.find(c);
      for (char i : letters->second)
      {
         string w(word);
         w.push_back(i);
         if (index == digits.size() - 1)
            result.push_back(w);
         else
            getCombination(m, index + 1, digits, w, result);
      }
   }
};

int main()
{

}