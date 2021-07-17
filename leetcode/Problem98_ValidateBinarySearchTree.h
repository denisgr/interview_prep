#pragma once

#include <functional>
#include <algorithm>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
   bool isValidBST(TreeNode* root) {
      std::vector<int> nums;
      InOrderTraverse(root, nums);
      return std::is_sorted(nums.begin(), nums.end());
   }

   void InOrderTraverse(TreeNode* node, std::vector<int>& nums)
   {
      if (!node)
         return;
      if (node->left)
      {
         InOrderTraverse(node->left, nums);
      }
      nums.push_back(node->val);
      if (node->right)
      {
         InOrderTraverse(node->right, nums);
      }
   }

};