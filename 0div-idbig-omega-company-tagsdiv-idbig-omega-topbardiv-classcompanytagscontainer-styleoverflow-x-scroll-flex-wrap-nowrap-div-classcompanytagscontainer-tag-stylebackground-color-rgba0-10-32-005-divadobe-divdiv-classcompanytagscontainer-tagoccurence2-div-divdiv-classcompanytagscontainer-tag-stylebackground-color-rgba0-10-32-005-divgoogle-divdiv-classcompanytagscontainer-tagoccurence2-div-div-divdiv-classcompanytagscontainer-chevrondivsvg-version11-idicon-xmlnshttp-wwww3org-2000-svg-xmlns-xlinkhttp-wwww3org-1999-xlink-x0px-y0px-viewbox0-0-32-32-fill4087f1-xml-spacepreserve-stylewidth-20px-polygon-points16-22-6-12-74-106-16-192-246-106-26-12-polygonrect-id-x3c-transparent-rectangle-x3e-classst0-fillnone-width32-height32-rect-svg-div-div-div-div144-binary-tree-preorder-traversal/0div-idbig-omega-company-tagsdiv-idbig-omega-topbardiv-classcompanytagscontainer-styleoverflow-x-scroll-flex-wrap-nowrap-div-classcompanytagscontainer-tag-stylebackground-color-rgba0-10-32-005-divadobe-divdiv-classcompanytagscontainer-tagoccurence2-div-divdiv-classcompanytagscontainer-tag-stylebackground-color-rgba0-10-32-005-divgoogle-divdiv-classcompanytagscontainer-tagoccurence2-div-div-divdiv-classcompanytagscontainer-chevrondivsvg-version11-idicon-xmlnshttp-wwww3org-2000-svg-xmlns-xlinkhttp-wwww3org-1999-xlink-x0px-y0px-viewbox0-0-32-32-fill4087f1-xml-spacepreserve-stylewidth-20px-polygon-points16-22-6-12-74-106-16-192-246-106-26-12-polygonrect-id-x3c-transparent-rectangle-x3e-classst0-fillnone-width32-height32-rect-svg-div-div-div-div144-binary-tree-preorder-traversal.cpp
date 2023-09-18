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
    void preorderTraversalRecursive(TreeNode* root, vector<int> &res)
    {
        if(root == NULL)
            return;
        
        res.push_back(root->val);
        preorderTraversalRecursive(root->left, res);
        preorderTraversalRecursive(root->right, res);
    }
    
    void preorderTraversalIterative(TreeNode* root, vector<int> &res)
    {
        if(root == NULL)
            return;
        
        stack<TreeNode*> st;
        st.push(root);
        
        while(!st.empty())
        {
            TreeNode* topNode = st.top();
            res.push_back(topNode->val);
            st.pop();
            
            if(topNode->right)
                st.push(topNode->right);
            
            if(topNode->left)
                st.push(topNode->left);                
            
        }
    }
    
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        
        preorderTraversalRecursive(root, res);
        
        return res;
    }
};