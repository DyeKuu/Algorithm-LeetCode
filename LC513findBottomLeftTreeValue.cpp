/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <queue>
using namespace std;
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        TreeNode* preNode = root;
        queue<TreeNode*> Q;
        Q.push(root);
        while (!Q.empty()) {
            preNode =  Q.front();
            Q.pop();
            if (preNode->right != nullptr) Q.push(preNode->right);
            if (preNode->left != nullptr) Q.push(preNode->left);
        }
        return preNode->val;
    }
};