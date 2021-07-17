// leetcode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Problem98_ValidateBinarySearchTree.h"

int main()
{

   Solution s;

   TreeNode* t = new TreeNode(0);
   TreeNode* t1 = new TreeNode(2);
   TreeNode* t2 = new TreeNode(4);
   TreeNode* t3 = new TreeNode(6);
   /*TreeNode* t4 = new TreeNode(119);
   TreeNode* t5 = new TreeNode(135);
   TreeNode* t6 = new TreeNode(150);
   TreeNode* t7 = new TreeNode(200);*/

   TreeNode* t9 = new TreeNode(1, t, t1);
   TreeNode* t10 = new TreeNode(5, t2, t3);
   /*TreeNode* t11 = new TreeNode(130, t4, t5);
   TreeNode* t12 = new TreeNode(160, t6, t7);*/

   /*TreeNode* t13 = new TreeNode(70, t9, t10);
   TreeNode* t14 = new TreeNode(140, t11, t12);*/

   TreeNode* t15 = new TreeNode(3, t9, t10);

   std::cout << s.isValidBST(t15);
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
