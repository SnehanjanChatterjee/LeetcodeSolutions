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
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ds;
        preorder(root, ds);
        return ds;
    }
    
    void preorder(TreeNode* root, vector<int> &ds) {
        if(root == NULL) return;
        
        ds.push_back(root->val);
        preorder(root->left, ds);
        preorder(root->right, ds);
    }
};