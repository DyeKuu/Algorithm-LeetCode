#include <cstdio>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lengthA = getLength(headA), lengthB = getLength(headB);
        if (lengthA > lengthB)
            for (int i = 1; i <= lengthA - lengthB; i++) headA = headA->next;
        else
            for (int i = 1; i <= lengthB - lengthA; i++) headB = headB->next;
        while (headA && headB && headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }

   private:
    int getLength(ListNode *head) {
        int res = 0;
        while (head) {
            head = head->next;
            res++;
        }
        return res;
    }
};
