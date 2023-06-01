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
    void rightSideView(TreeNode* root, int level, vector<int> &res) {
        if(root == NULL)
            return;
        
        if(res.size() == level)
            res.push_back(root->val);
        
        rightSideView(root->right, level+1, res);
        rightSideView(root->left, level+1, res);        
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        
        rightSideView(root, 0, res);
        
        return res;
    }
};