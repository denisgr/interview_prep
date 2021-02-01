#include <iostream>
#include <string>
#include <unordered_set>
#include <sstream>
#include <unordered_map>
using namespace std;



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
      auto s = size(head);
      if (s == 1)
         return nullptr;
      size_t index = 0;
      ListNode* h = head;
      if (n == s)
      {
         head = head->next;
         return head;
      }
      while (index != s - n - 1)
      {
         h = h->next;
         index++;
      }

      if (n == 1)
      {
         h->next = nullptr;
      }
      if (h->next && h->next->next)
      {
         h->next = h->next->next;
      }

      return head;
   }

   size_t size(ListNode* head)
   {
      size_t size = 0;
      while (head->next != nullptr)
      {
         size++;
         head = head->next;
      }
      size++;
      return size;
   }
};

int main()
{
   ListNode* h = new ListNode(1);
   ListNode* h2 = new ListNode(2);
   h->next = h2;
   Solution s;
   s.removeNthFromEnd(h, 1);
}