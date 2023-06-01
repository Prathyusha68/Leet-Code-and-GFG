#include <bits/stdc++.h>
/*
    template <typename T = int>
    class TreeNode
    {
        public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode()
        {
            if (left != NULL)
            {
                delete left;
            }
            if (right != NULL)
            {
                delete right;
            }
        }
    };
*/

bool pathInATree(TreeNode<int> *root, vector<int> &path, int x)
{
    if (!root)
        return false;

    path.push_back(root->data);

    if (root->data == x)
        return true;

    if (pathInATree(root->left, path, x) || pathInATree(root->right, path, x))
        return true;

    path.pop_back();
    return false;
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    vector<int> path;
    pathInATree(root, path, x);

    return path;
}
