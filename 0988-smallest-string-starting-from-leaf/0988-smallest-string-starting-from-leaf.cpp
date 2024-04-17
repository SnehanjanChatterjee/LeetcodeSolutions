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
    void dfs(TreeNode* root, string str, priority_queue<string, vector<string>, greater<string>> &minHeap) {
        if(root->left == NULL && root->right == NULL) {
            reverse(str.begin(), str.end());
            minHeap.push(str);
            return;
        }
        
        if(root->left != NULL) {
            str.push_back('a' + root->left->val);
            dfs(root->left, str, minHeap);
            str.pop_back();
        }
        if(root->right != NULL) {
            str.push_back('a' + root->right->val);
            dfs(root->right, str, minHeap);
            str.pop_back();
        }
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        priority_queue<string, vector<string>, greater<string>> minHeap;
        string str = "";
        str.push_back(('a' + root->val));
        dfs(root, str, minHeap);
        return minHeap.top();
    }
};