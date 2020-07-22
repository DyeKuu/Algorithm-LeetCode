struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

#include <queue>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (!root) return res;
        vector<int> eachLevel;
        queue<TreeNode *> Q;
        Q.push(root);
        int thisCount = 1, nextCount = 0, level = 0;
        while (!Q.empty()) {
            TreeNode *curr = Q.front();
            Q.pop();
            eachLevel.push_back(curr->val), thisCount--;
            if (curr->left) Q.push(curr->left), nextCount++;
            if (curr->right) Q.push(curr->right), nextCount++;
            if (!thisCount) {
                thisCount = nextCount, nextCount = 0;
                if (level++ % 2) reverse(eachLevel.begin(), eachLevel.end());
                res.push_back(eachLevel);
                eachLevel.clear();
            }
        }
        return res;
    }
};
