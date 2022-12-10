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
    const int MOD = 1000000007;
    void totalSum(TreeNode* root, int &total) {
        if(!root) return;
        
        total = (total + root->val) % MOD;
        
        totalSum(root->left, total);
        totalSum(root->right, total);
    }
    void subtree(TreeNode* root, int &total, long &maxProd) {
        if(!root) return;
        
        int subtreeTotal = 0;
        totalSum(root, subtreeTotal);
        
        maxProd = max(maxProd*1L, (((total*1L - subtreeTotal*1L) * subtreeTotal*1L)));
        
        subtree(root->left, total, maxProd);
        subtree(root->right, total, maxProd);
    }
    int mySolution(TreeNode* root) { // TLE
        int total = 0;
        long maxProd = INT_MIN;
        totalSum(root, total);
        subtree(root, total, maxProd);
        return maxProd % MOD;
    }
    
    // https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/discuss/1412940/C%2B%2B-Simple-and-Short-Recursive-Solution-Faster-than-99
    long res = 0, total = 0;
    int rec(TreeNode* root) {
        if (!root) return 0;
        int subtree = rec(root->left) + rec(root->right) + root->val;
        res = max(res, (total - subtree) * subtree);
        return subtree;
    }
    int otherSolution(TreeNode* root) {
        total = rec(root);
        rec(root);
        return res % int(pow(10,9)+7);
    }
public:
    int maxProduct(TreeNode* root) {
        // return mySolution(root);
        
        return otherSolution(root);
        
    }
};