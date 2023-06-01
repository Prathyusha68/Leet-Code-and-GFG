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
    bool isValidBst(TreeNode* root, long min, long max)
    {
        if(root == nullptr)
            return true;
        
        if((root->val >= max) || (root->val <= min))
            return false;
        
        return (isValidBst(root->left, min, root->val) &&
                isValidBst(root->right, root->val, max));
    }
    
public:
    bool isValidBST(TreeNode* root) {
        return isValidBst(root, LONG_MIN, LONG_MAX);
    }
};