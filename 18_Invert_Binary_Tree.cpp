// Invert a BinaryTree (LEETCODE JUNE CHALLENGE (2020) Week 1 - Q1)

//Recursion
TreeNode *invertBinaryTree(TreeNode *root)
{
    if (!root->left && !root->right)
    {
        return NULL;
    }
    TreeNode *left = invertBinaryTree(root->right);
    TreeNode *right = invertBinaryTree(root->left);
    root->left = left;
    root->right = right;
    return root;
}

// BFS
TreeNode *invertBinaryTree(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        if (node != NULL)
        {
            TreeNode *left = root->right;
            TreeNode *right = root->left;
            root->left = left;
            root->right = right;
            q.push(node->left);
            q.push(node->right);
        }
    }
    return root;
}