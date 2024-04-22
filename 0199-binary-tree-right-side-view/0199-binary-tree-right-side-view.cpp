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
    // https://www.youtube.com/watch?v=KV4mRzTjlAk 
    void recursion(TreeNode *root, int level, vector<int> &res)
    {
        if(root==NULL) return ;
        // If we are traverse in order : right, left - that means right node will be added first, and result size will increase by 1 (and will equal level size), so when left node (if any) is visited, result == level, hence it won't be added. 
        // You only add one node per level. And this preorder recurs right node first. So at each level you will add rightmost and others will automatically get skipped.
        // We will push one element at each level. So, the size of the res vector will actually be equal to the number of levels we have already stored the result. If the level of some element is more than the size of res vector that means this will be a new level for which we have not pushed anything in the res vector. So, we will push this element in the res vector. The size of res in next iterations will increase by one and for all the other elements in same level res.size() < level will be false
        if(res.size()<level) res.push_back(root->val);
        recursion(root->right, level+1, res);
        recursion(root->left, level+1, res);
    }

    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        recursion(root, 1, res);
        return res;
    }
    
};