struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

#include <map>
#include <vector>
using namespace std;
class Solution {
   public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        map<int, int> M;
        for (int i = 0; i < inorder.size(); i++) M[inorder[i]] = i;
        return buildTreeWithRange(inorder, postorder, 0, inorder.size() - 1, 0,
                                  postorder.size() - 1, M);
    }

   private:
    static inline TreeNode *buildTreeWithRange(vector<int> &inorder,
                                               vector<int> &postorder,
                                               int inorderBegin, int inorderEnd,
                                               int postorderBegin,
                                               int postorderEnd,
                                               map<int, int> &M) {
        if (inorderEnd < inorderBegin || postorderEnd < postorderBegin)
            return nullptr;
        int rootValue = postorder[postorderEnd];
        int rootIndinInorder = M[rootValue];
        return new TreeNode(
            rootValue,
            buildTreeWithRange(
                inorder, postorder, inorderBegin, rootIndinInorder - 1,
                postorderBegin,
                postorderBegin + rootIndinInorder - inorderBegin - 1, M),
            buildTreeWithRange(inorder, postorder, rootIndinInorder + 1,
                               inorderEnd,
                               postorderEnd - inorderEnd + rootIndinInorder,
                               postorderEnd - 1, M));
    }
};
