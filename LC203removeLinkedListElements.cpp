struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *pre = nullptr, *curr = head;
        while (curr) {
            while (curr && curr->val == val) {
                if (curr == head) {
                    head = head->next;
                    curr = head;
                } else {
                    pre->next = curr->next;
                    curr = curr->next;
                }
            }
            if (curr) {
                pre = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};
