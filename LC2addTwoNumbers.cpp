struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        long len1 = getLength(l1);
        long len2 = getLength(l2);
        return (len1 >= len2) ? addTwoNumbersL1IsLonger(l1, l2)
                              : addTwoNumbersL1IsLonger(l2, l1);
    }

   private:
    long getLength(ListNode *l) {
        long i = 0;
        while (l != nullptr) {
            l = l->next;
            i++;
        }
        return i;
    }
    ListNode *addTwoNumbersL1IsLonger(ListNode *l1, ListNode *l2) {
        ListNode *a = new ListNode();
        ListNode *p = a;
        int overflow = 0;
        while (l2 != nullptr) {
            int sum = l1->val + l2->val + overflow;
            p->val = sum % 10;
            overflow = sum / 10;
            l1 = l1->next;
            l2 = l2->next;
            ListNode *newL = new ListNode();
            p->next = newL;
            p = p->next;
        }
        while (l1 != nullptr) {
            int sum = l1->val + overflow;
            p->val = sum % 10;
            overflow = sum / 10;
            l1 = l1->next;
            ListNode *newL = new ListNode();
            p->next = newL;
            p = p->next;
        }
        p->val = overflow;
        checkAndRemoveTailZero(a);
        return a;
    }

    void checkAndRemoveTailZero(ListNode *l) {
        ListNode *p = l;
        if (p->next == nullptr) return;
        while (p->next->next != nullptr) p = p->next;
        if (p->next->val == 0) {
            delete p->next;
            p->next = nullptr;
        }
    }
};
