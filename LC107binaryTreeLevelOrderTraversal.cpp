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
class Solution {
   public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        vector<int> init;

        TreeNode *preNode = root;
        int thisCount = 1;
        int nextCount = 0;
        int depth = 0;
        queue<TreeNode *> Q;
        Q.push(root);
        while (!Q.empty()) {
            preNode = Q.front();
            init.emplace(init.begin(), preNode->val);
            Q.pop();
            thisCount--;
            if (preNode->right != nullptr) {
                Q.push(preNode->right);
                nextCount++;
            }
            if (preNode->left != nullptr) {
                Q.push(preNode->left);
                nextCount++;
            }
            if (!thisCount) {
                res.emplace(res.begin(), init);
                init.clear();
                depth++;
                thisCount = nextCount;
                nextCount = 0;
            }
        }
        return res;
    }
};