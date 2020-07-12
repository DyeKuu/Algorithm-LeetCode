class Node {
   public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
#include <stack>
using namespace std;
class Solution {
   public:
    Node* flatten(Node* head) {
        if (head == nullptr) return head;
        stack<Node*> S;
        Node* curr = head;
        while (curr->next || curr->child) {
            while (curr->child) {
                if (curr->next) S.push(curr->next);
                ((curr->next = curr->child)->prev = curr)->child = nullptr;
            }
            curr = curr->next;
            if (!(curr->next || S.empty()))
                (curr->next = S.top())->prev = curr, S.pop();
        }
        return head;
    }
};
