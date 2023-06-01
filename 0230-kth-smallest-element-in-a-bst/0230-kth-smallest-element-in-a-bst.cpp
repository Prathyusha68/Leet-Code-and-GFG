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
    TreeNode* kthSmallestNode(TreeNode* root, int &k) {
        if(!root)
            return root;
        
        TreeNode* left = kthSmallestNode(root->left, k);
        
        if(left != NULL)
            return left;
        
        k--;
        
        if(k == 0)
            return root;
        
        return kthSmallestNode(root->right, k);
    }
    
public:
    int kthSmallest(TreeNode* root, int k) {
        if(!root)
            return -1;
        
        TreeNode* node = kthSmallestNode(root, k);
        if(!node)
            return -1;
        else
            return node->val;     
    }
};