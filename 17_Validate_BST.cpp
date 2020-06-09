// check whether a BST is valid

bool dfs(TreeNode *root, int minlim, int maxlim)
{
    if (!root)
    {
        return true;
    }
    if ((root->val <= minlim) || (root->val < maxlim))
    {
        return false;
    }
    return dfs(root->left, minlim, root->val) || dfs(root->right, root->val, maxlim);
}

bool validateBST(TreeNode *root)
{
    return dfs(root, INT_MIN, INTMAX)
}