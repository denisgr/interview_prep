#pragma once

class Solution {
public:
   double myPow(double x, int n) {
      double arr[10];

      arr[0] = x;
      for (int i = 0; i < 9; ++i)
      {
         arr[i + 1] = 1.0;
         for (int j = 0; j < 10; ++j)
         {
            arr[i + 1] *= arr[i];
         }
      }

      double res = 1.0;
      bool negative = n < 0;
      n = negative ? -1 * n : n;
      while (n > 0)
      {
         int index = 1;
         for (int i = 1; i < 10; ++i)
         {
            index *= 10;

            if (i == 9)
            {
               n -= index;
               res *= arr[i];
            }
            else if (n - index > 0)
            {
            }
            else
            {
               n -= index / 10;
               res *= arr[i - 1];
               break;
            }
         }
      }
      return negative ? 1.0 / res : res;
   }
};