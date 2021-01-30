#include <iostream>

struct ListNode {
   int val;
   ListNode* next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
   ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      int carry = 0;
      auto* result = new ListNode(0);
      auto* currentNode = result;
      while (l1 != nullptr || l2 != nullptr || carry)
      {
         if (l1)
         {
            currentNode->val += l1->val;
            l1 = l1->next;
         }
         if (l2)
         {
            currentNode->val += l2->val;
            l2 = l2->next;
         }
         currentNode->val += carry;

         if (currentNode->val > 9)
         {
            carry = 1;
            currentNode->val %= 10;
         }
         else
         {
            carry = 0;
         }
         if (l1 || l2 || carry)
         {
            currentNode->next = new ListNode(0);
            currentNode = currentNode->next;
         }
         else
            currentNode->next = nullptr;
      }

      return result;
   }
};

int main()
{

}