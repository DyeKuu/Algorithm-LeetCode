
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
    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        return isMirror(root->left, root->right);
    }

   private:
    bool isMirror(TreeNode *leftTree, TreeNode *rightTree) {
        if (!(leftTree || rightTree)) return true;
        if (!(leftTree && rightTree)) return false;
        return leftTree->val == rightTree->val &&
               isMirror(leftTree->left, rightTree->right) &&
               isMirror(leftTree->right, rightTree->left);
    }
};
