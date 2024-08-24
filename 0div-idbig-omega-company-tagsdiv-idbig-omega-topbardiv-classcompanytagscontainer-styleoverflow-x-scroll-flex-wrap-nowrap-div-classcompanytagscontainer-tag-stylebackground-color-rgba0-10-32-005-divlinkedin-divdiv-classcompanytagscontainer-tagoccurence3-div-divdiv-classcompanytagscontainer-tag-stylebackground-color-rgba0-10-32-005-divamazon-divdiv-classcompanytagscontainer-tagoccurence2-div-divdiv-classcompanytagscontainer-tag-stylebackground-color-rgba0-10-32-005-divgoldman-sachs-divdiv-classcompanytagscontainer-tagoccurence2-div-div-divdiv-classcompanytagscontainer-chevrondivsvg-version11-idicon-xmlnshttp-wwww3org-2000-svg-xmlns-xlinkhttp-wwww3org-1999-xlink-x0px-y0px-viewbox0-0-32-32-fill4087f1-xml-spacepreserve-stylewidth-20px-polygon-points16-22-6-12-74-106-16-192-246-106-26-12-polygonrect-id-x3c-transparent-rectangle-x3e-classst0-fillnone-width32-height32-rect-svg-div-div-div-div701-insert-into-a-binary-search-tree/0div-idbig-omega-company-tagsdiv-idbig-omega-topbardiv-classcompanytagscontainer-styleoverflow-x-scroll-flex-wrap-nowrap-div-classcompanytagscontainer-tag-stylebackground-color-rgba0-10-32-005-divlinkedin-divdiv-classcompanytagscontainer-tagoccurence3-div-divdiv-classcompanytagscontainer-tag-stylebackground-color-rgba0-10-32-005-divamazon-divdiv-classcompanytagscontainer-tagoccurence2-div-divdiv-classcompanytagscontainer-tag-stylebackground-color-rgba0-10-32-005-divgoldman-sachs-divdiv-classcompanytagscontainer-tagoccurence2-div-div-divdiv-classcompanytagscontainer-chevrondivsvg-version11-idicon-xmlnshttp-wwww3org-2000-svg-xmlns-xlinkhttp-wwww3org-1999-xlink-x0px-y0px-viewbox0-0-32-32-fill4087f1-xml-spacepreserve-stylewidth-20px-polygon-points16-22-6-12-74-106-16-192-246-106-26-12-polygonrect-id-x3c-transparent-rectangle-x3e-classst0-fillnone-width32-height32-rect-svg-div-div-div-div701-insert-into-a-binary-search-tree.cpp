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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* tmp = new TreeNode(val);
        if(root == NULL)
            return tmp;

        TreeNode* curr = root;

        while(curr)
        {
            if(curr->val > val)
            {
                if(curr->left == NULL)
                {
                    curr->left = tmp;
                    break;
                }

                curr = curr->left;
            }
            else
            {
                if(curr->right == NULL)
                {
                    curr->right = tmp;
                    break;
                }

                curr = curr->right;
            }
        }

        return root;
    }
};