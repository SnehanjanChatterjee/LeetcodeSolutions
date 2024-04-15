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
    void dfs(TreeNode* root, string num, int &sum) {
        if(root->left == NULL && root->right == NULL) {
            sum += stoi(num);
            return;
        }
        
        if(root->left != NULL) {
            dfs(root->left, num + to_string(root->left->val), sum);
        }
        if(root->right != NULL) {
            dfs(root->right, num + to_string(root->right->val), sum);
        }
    }
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        dfs(root, to_string(root->val), sum);
        return sum;
    }
};