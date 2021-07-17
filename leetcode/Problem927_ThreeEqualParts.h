#pragma once

#include <vector>
#include <algorithm>

class Solution {
public:
   std::vector<int> threeEqualParts(std::vector<int>& arr) {
      using namespace std;
      int countOfOnes = count_if(arr.begin(), arr.end(), [](int val) { return val == 1; });
      if (countOfOnes % 3 != 0)
         return { -1, -1 };

      if (countOfOnes == 0)
         return { 0, 2 };
      int leadingZeros = 0;
      while (!arr.empty() && arr.front() == 0)
      {
         leadingZeros++;
         arr.erase(arr.begin());
      }

      int i = 0, j = 0;
      int countOfOnesInOnePart = countOfOnes / 3;
      int index = 0;
      while (i < countOfOnesInOnePart)
      {
         if (arr[index] == 1)
         {
            i++;
            if (i == countOfOnesInOnePart)
               break;
         }
         index++;
      }

      int index2 = arr.size() - 1;
      while (j < countOfOnesInOnePart)
      {
         if (arr[index2] == 1)
         {
            j++;
            if (j == countOfOnesInOnePart)
               break;
         }
         index2--;
      }

      if (arr.size() - index2 - 1 > index + 1)
      {
         index = arr.size() - index2 - 1;
      }

      while (index < index2)
      {
         j = 0;
         i = arr.size() - 1;
         while (j < countOfOnesInOnePart && arr[i] == arr[index - (arr.size() - i - 1)] && i > index + 1)
         {
            if (arr[i] == 1)
            {
               j++;
               if (j == countOfOnesInOnePart)
                  break;
            }
            i--;
         }

         if (j == countOfOnesInOnePart)
         {
            int k = 0;
            int index3 = index2 - 1;
            int tmp = arr.size() - 1;
            while (k < countOfOnesInOnePart && arr[index3] == arr[tmp] && tmp >= index2)
            {
               if (arr[index3] == 1)
               {
                  k++;
                  if (k == countOfOnesInOnePart)
                     break;
               }
               index3--;
               tmp--;
            }
            if (k == countOfOnesInOnePart)
            {
               return { index + leadingZeros, index2 + leadingZeros };
            }
            else
            {
               index2--;
               if (arr[index2] == 1)
               {
                  return { -1, -1 };
               }
            }
         }
         else
         {
            index++;
            if (arr[index] == 1)
            {
               return { -1, -1 };
            }
         }
      }
      return { -1, -1 };
   }
};