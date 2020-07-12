/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return head;
        ListNode *nextnode, *prenode = nullptr, *currnode = head;
        while (currnode) {
            nextnode = currnode->next;
            currnode->next = prenode;
            prenode = currnode;
            currnode = nextnode;
        }
        return prenode;
        
    }
};

class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return head;
        ListNode *nextnode, *nextnextnode;
        if (head->next) {
            nextnode = head->next;
            head->next = nullptr;
            while (nextnode->next != nullptr) {
                nextnextnode = nextnode->next;
                nextnode->next = head;
                head = nextnode;
                nextnode = nextnextnode;
            }
            nextnode->next = head;
            head = nextnode;
            
        }
        return head;
        
    }
};
