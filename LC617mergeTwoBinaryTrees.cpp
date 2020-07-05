struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
   public:
    TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2) {
        if (t1 == nullptr) return t2;
        if (t2 == nullptr) return t1;
        t2->val += t1->val;
        t2->left = mergeTrees(t1->left, t2->left);
        t2->right = mergeTrees(t1->right, t2->right);
        return t2;
    }
};
