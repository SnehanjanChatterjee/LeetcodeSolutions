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
class Solution {
private:
    int recur(TreeNode *root, bool isLeft) {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) { // Leaf Node
            if(isLeft)  return root->val;
            else return 0;
        }
        return recur(root->left, true) + recur(root->right, false);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return recur(root, false);
    }
};