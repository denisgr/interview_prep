#pragma once
#include <sstream>

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
   bool isSymmetric(TreeNode* root) {
      std::ostringstream ossl, ossr;
      leftTraverse(root->left, ossl, 0, 0);
      rightTraverse(root->right, ossr, 0, 0);
      return ossl.str() == ossr.str();
   }

   void leftTraverse(TreeNode* t, std::ostringstream& r, int kind, int level)
   {
      if (t == nullptr)
         return;
      r << level << " " << kind << " " << t->val << "|";
      leftTraverse(t->left, r, 0, level + 1);
      leftTraverse(t->right, r, 1, level + 1);
   }

   void rightTraverse(TreeNode* t, std::ostringstream& r, int kind, int level)
   {
      if (t == nullptr)
         return;
      r << level << " " << kind << " " << t->val << "|";
      rightTraverse(t->right, r, 0, level + 1);
      rightTraverse(t->left, r, 1, level + 1);
   }
};