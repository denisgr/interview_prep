#pragma once

#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
private:
   static void serialize(std::ostringstream& out, TreeNode* node, int level, int kind)
   {
      if (node)
         out << node->val << '@' << level << '@' << kind << '|';
      else
         return;

      if (node->left)
      {
         serialize(out, node->left, level + 1, 0);
      }

      if (node->right)
      {
         serialize(out, node->right, level + 1, 1);
      }
   }

   static void deserialize(TreeNode*& node, std::vector<std::string>& nodeStrs, int level, int kind)
   {
      if (nodeStrs.empty())
         return;
      std::string nodeStr = nodeStrs.back();
      std::vector<std::string> nodeData = split(nodeStr, '@');
      int data = std::stoi(nodeData[0]);
      int nodeLevel = std::stoi(nodeData[1]);
      int nodeKind = std::stoi(nodeData[2]);
      if (nodeLevel == level && nodeKind == kind)
      {
         nodeStrs.pop_back();
         node = new TreeNode(data);
         deserialize(node->left, nodeStrs, level + 1, 0);
         deserialize(node->right, nodeStrs, level + 1, 1);
      }
   }

   static std::vector<std::string> split(std::string tokens, char delimeter)
   {
      using namespace std;
      vector<string> result;
      istringstream iss(tokens);
      string item;
      while (std::getline(iss, item, delimeter))
      {
         result.push_back(item);
      }
      return result;
   }

public:

   // Encodes a tree to a single string.
   std::string serialize(TreeNode* root) {
      std::ostringstream oss;
      serialize(oss, root, 0, 0);
      std::string result = oss.str();
      if (!result.empty())
         result.pop_back();
      return result;
   }

   // Decodes your encoded data to tree.
   TreeNode* deserialize(std::string data) {
      std::vector<std::string> tokens = split(data, '|');
      std::reverse(tokens.begin(), tokens.end());
      TreeNode* root = nullptr;
      if (!tokens.empty())
         deserialize(root, tokens, 0, 0);
      return root;
   }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));