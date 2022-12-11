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
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        findMaxPathSum(root, maxSum);
        return maxSum;
    }
    
    int findMaxPathSum(TreeNode* root, int &maxSum) {
        if(root == NULL) return 0;
        
        // Don't Consider -ve nos. If -ve, make it 0.
        int leftSum = max(0, findMaxPathSum(root->left, maxSum));
        int rightSum = max(0, findMaxPathSum(root->right, maxSum));

        maxSum = max(maxSum, (root->val + leftSum + rightSum));
        
        // [In order to know which path to take take max of left and right.
        // The path with max sum is considered.]
        // Lets consider example 2. For current node 20, I know what is the maxSum.
        // (leftSum 15, rightSum 7) So sum = 20+15+7 = 42 for a path passing through 20
        // But when I will return to caller node -10, for a path passing from -10 to 20, it will either go through 15 or 7.
        // So check which is greater, leftSum/rightSum and pass that sum only
        // So path from -10 will be 10 -> 20 > 15.
        return (root->val + max(leftSum, rightSum));
    }
};