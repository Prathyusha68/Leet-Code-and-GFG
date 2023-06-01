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
    int maxPathSum(TreeNode* root, int &maxSum)
    {
        if(root == nullptr)
            return 0;
        
        int lh = max(0, maxPathSum(root->left, maxSum));
        int rh = max(0, maxPathSum(root->right, maxSum));
        
        int data = root->val;
        
        maxSum = max(maxSum, lh+rh+data);
        
        return data+max(lh, rh);
    }
    
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        
        maxPathSum(root, maxSum);
        return maxSum;
    }
};