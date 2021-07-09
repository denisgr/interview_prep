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
   ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode* current = head;
      int size = 0;
      while (current != nullptr)
      {
         size++;
         current = current->next;
      }

      n = size - n;
      current = head;
      while (n > 1)
      {
         n--;
         current = current->next;
      }

      if (n == 0)
      {
         if (size == 1)
         {
            return nullptr;
         }
         else
         {
            head = head->next;
         }
      }
      else if (current->next && current->next->next)
      {
         current->next = current->next->next;
      }
      else if (current->next && !current->next->next)
      {
         current->next = nullptr;
      }
      return head;
   }
};