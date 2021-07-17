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
   std::vector<int> inorderTraversal(TreeNode* root) {
      std::vector<int> res;
      traverse(root, res);
      return res;
   }

   void traverse(TreeNode* node, std::vector<int>& res)
   {
      if (!node)
         return;

      if (node->left)
         traverse(node->left, res);

      res.push_back(node->val);

      if (node->right)
         traverse(node->right, res);
   }
};