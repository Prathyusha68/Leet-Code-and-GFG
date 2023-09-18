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
    void inorderTraversalRecursive(TreeNode* root, vector<int> &res)
    {
        if(root == NULL)
            return;
        
        inorderTraversalRecursive(root->left, res);
        res.push_back(root->val);
        inorderTraversalRecursive(root->right, res);
    }

    void inorderTraversalIterative(TreeNode* root, vector<int> &res)
    {
        if(root == NULL)
            return;
        
        stack<TreeNode*> st;
        st.push(root);

        
    }
    
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        
        inorderTraversalRecursive(root, res);
        
        return res;
    }
};