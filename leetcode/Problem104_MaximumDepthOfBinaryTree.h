#pragma once

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
   int maxDepth(TreeNode* root) {
      int max = 0;
      findMaxDepth(root, max, 0);
      return max;
   }

   void findMaxDepth(TreeNode* node, int& max, int level)
   {
      if (!node)
         return;
      max = std::max(max, level + 1);
      if (node->left)
         findMaxDepth(node->left, max, level + 1);
      if (node->right)
         findMaxDepth(node->right, max, level + 1);
   }
};