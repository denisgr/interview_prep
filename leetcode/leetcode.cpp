// leetcode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Problem297_SerializeAndDeserializeBinaryTree.h"
int main()
{
   Codec c;

   TreeNode* t = new TreeNode(1);
   /*t->left = new TreeNode(2);
   t->right = new TreeNode(3);
   auto tempNode = t->right;
   tempNode->left = new TreeNode(4);
   tempNode->right = new TreeNode(5);*/
   t->left = nullptr;
   t->right = new TreeNode(2);
   t = c.deserialize(c.serialize(t));
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
