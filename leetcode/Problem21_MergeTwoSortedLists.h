#pragma once

struct ListNode {
   int val;
   ListNode* next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode* next) : val(x), next(next) {}
   
};
class Solution {
public:
   ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      ListNode *head = nullptr, *current = nullptr;

      while (l1 != nullptr && l2 != nullptr)
      {
         if (l1->val < l2->val)
         {
            if (current)
            {
               current->next = new ListNode(l1->val);
               current = current->next;
            }
            else
               current = new ListNode(l1->val);
            l1 = l1->next;
         }
         else
         {
            if (current)
            {
               current->next = new ListNode(l2->val);
               current = current->next;
            }
            else
               current = new ListNode(l2->val);
            l2 = l2->next;
         }
         if (!head)
            head = current;
      }
      while (l1 != nullptr)
      {
         if (current)
         {
            current->next = new ListNode(l1->val);
            current = current->next;
         }
         else
            current = new ListNode(l1->val);

         if (!head)
            head = current;

         l1 = l1->next;
      }
      while (l2 != nullptr)
      {
         if (current)
         {
            current->next = new ListNode(l2->val);
            current = current->next;
         }
         else
            current = new ListNode(l2->val);

         if (!head)
            head = current;

         l2 = l2->next;
      }
      return head;
   }
};