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
        
        // At current node, calculate the difference b/w current node value and
        // the min value till now and max value till now in current path.
        // If any of the differences are greater than maxDiff, maxDiff will be updated
        maxDiff = max(maxDiff, max(abs(root->val - maxVal), abs(root->val - minVal)));
        
        // Pass the min value till now and max value till now in current path
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