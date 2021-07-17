#pragma once

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
   std::vector<std::vector<int>> levelOrder(TreeNode* root) {
      std::vector<std::vector<int>> res;
      levelTraverse(root, res, 0);
      return res;
   }

   void levelTraverse(TreeNode* node, std::vector<std::vector<int>>& res, int level)
   {
      if (!node)
         return;
      if (res.size() <= level)
         res.push_back(std::vector<int>());
      auto& v = res[level];
      v.push_back(node->val);
      if (node->left)
         levelTraverse(node->left, res, level + 1);
      if (node->right)
         levelTraverse(node->right, res, level + 1);
   }
};