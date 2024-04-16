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
    TreeNode* head;
    void dfs(TreeNode* curNode, TreeNode* prevNode, int val, int curDepth, int depth) {
        if(curDepth==depth) {
            TreeNode* newNode = new TreeNode(val);
            if(prevNode!=NULL && prevNode->left==curNode) {
                newNode->left = curNode;
                prevNode->left = newNode;
            }
            else if(prevNode!=NULL && prevNode->right==curNode) {
                newNode->right = curNode;
                prevNode->right = newNode;
            }
            else { // curNode is the root of the tree
                newNode->left = curNode;
                head = newNode;
            }
            return;
        }
        
        if(curNode == NULL) return;
        dfs(curNode->left, curNode, val, curDepth+1, depth);
        dfs(curNode->right, curNode, val, curDepth+1, depth);
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        head = root;
        dfs(root, NULL, val, 1, depth);
        return head;
    }
};