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

using namespace std;
class Solution {
   public:
    int maxDepth(TreeNode *root) {
        if (root == nullptr) return 0;
        int depth = 0;
        queue<TreeNode *> Q;
        Q.push(root);
        depth = 0;
        int thisCount = 1;
        int nextCount = 0;
        while (!Q.empty()) {
            TreeNode *node = Q.front();
            Q.pop();
            thisCount--;
            if (node->left != nullptr) Q.push(node->left), nextCount++;
            if (node->right != nullptr) Q.push(node->right), nextCount++;
            if (!thisCount) depth++, thisCount = nextCount, nextCount = 0;
        }
        return depth;
    }
};
