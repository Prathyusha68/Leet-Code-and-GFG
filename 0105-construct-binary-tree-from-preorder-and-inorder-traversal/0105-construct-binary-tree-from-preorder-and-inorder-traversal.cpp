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
    TreeNode* buildTree(vector<int>& preorder, int pStart, int pEnd,
                        vector<int>& inorder, int iStart, int iEnd, map<int, int> mp) {
        if((pStart > pEnd) || (iStart > iEnd))
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[pStart]);
        
        int rootAt = mp[root->val];
        int numElem = rootAt-iStart;
        
        root->left = buildTree(preorder, pStart+1, pStart+numElem,
                         inorder, iStart, rootAt-1, mp);
        root->right = buildTree(preorder, pStart+numElem+1, pEnd,
                         inorder, rootAt+1, iEnd, mp);
        
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int rootIdx = 0;
        return build(preorder, inorder, rootIdx, 0, inorder.size()-1);
    }
    
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& rootIdx, int left, int right) {
        if (left > right) return NULL;
        int pivot = left;  // find the root from inorder
        while(inorder[pivot] != preorder[rootIdx]) pivot++;
        
        rootIdx++;
        TreeNode* newNode = new TreeNode(inorder[pivot]);
        newNode->left = build(preorder, inorder, rootIdx, left, pivot-1);
        newNode->right = build(preorder, inorder, rootIdx, pivot+1, right);
        return newNode;
    }
};