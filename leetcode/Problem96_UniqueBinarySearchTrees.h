#pragma once
#include <math.h> 
class Solution {
public:
   int numTrees(int n) {
      int G[20] = { 0 };
      G[0] = G[1] = 1;

      for (int i = 2; i < 20; ++i)
      {
         for (int j = 0; j < i; ++j)
         {
            G[i] += G[j] * G[i - j - 1];
         }
      }
      return G[n];
   }
};