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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        
        queue<pair<TreeNode*, int>> q;
        
        q.push({root, 0});
        
        int width = 0;
        
        while(!q.empty())
        {
            int size = q.size();
            int minId = q.front().second;
            int rightMost, leftMost;
            
            for(int i = 0; i < size; i++)
            {
                // to avoid integer overflow start from "0" for each level
                int currId = q.front().second - minId; 
                TreeNode* node = q.front().first;
                q.pop();
                
                if(i == 0)
                    leftMost = currId;
                if(i == size-1)
                    rightMost = currId;
                
                if(node->left)
                    q.push({node->left, (long long)2*currId+1});
                
                if(node->right)
                    q.push({node->right, (long long)2*currId+2});                    
                
            }
            
            width = max(width, rightMost-leftMost+1);
        }
        
        return width;
    }
};