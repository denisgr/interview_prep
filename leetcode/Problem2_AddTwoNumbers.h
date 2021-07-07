#pragma once


struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
   ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode *head = nullptr, *current = nullptr;
      int carry = 0;
      while (l1 != nullptr && l2 != nullptr)
      {
         int digit = (l1->val + l2->val + carry) % 10;
         carry = l1->val + l2->val > 9 ? 1 : 0;
         if (current)
         {
            current->next = new ListNode(digit);
            current = current->next;
         }
         else
            current = new ListNode(digit);

         if (!head)
            head = current;

         l1 = l1->next;
         l2 = l2->next;
      }

      while (l1 != nullptr)
      {
         int digit = (l1->val + carry) % 10;
         carry = l1->val + carry > 9 ? 1 : 0;
         if (current)
         {
            current->next = new ListNode(digit);
            current = current->next;
         }
         else
            current = new ListNode(digit);

         if (!head)
            head = current;

         l1 = l1->next;
      }

      while (l2 != nullptr)
      {
         int digit = (l2->val + carry) % 10;
         carry = l2->val + carry > 9 ? 1 : 0;
         if (current)
         {
            current->next = new ListNode(digit);
            current = current->next;
         }
         else
            current = new ListNode(digit);

         if (!head)
            head = current;

         l2 = l2->next;
      }

      if (carry > 0)
         current->next = new ListNode(carry);

      return head;
   }
};