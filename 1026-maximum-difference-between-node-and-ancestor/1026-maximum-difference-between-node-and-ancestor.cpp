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
    void preorder(TreeNode* root, int &maxDiff, int minVal, int maxVal) {
        if(root==NULL) return;
        
        if(abs(root->val - maxVal) > maxDiff) maxDiff = abs(root->val - maxVal);
        if(abs(root->val - minVal) > maxDiff) maxDiff = abs(root->val - minVal);
        
        preorder(root->left, maxDiff, min(minVal, root->val), max(maxVal, root->val));
        preorder(root->right, maxDiff, min(minVal, root->val), max(maxVal, root->val));
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        int maxDiff = 0, minVal = INT_MAX, maxVal = INT_MIN;
        preorder(root, maxDiff, root->val, root->val);
        return maxDiff;
    }
};