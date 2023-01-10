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
    // Pre-order traversal. Iteratively checking for each subtree if they are same.
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If reached null, both should be null in order for tree to be same
        if(p == NULL || q == NULL) return p==q;
        
        // We can do any DFS travelsal and keep checking if current node's val is same and left, right subtree is also same
        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};