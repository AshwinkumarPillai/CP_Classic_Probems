// Given a Binary Search Tree and an integer k, find the value in the BST which is closest to the integer k.

// Using Recursion
int dfs(TreeNode *root, int k, int ans)
{
    if (!root)
        return;
    if (abs(root->val - k) <= abs(ans - k))
    {
        ans = root->val;
    }
    if (root->val == k)
    {
        return ans;
    }
    else if (root->val > k)
    {
        return dfs(root->left, k, ans);
    }
    return dfs(root->right, k, ans);
}

int ClosestInteger(TreeNode *root, int k)
{
    return dfs(root, k, INT_MAX)
}

// Using Iteration

int ClosestInterger(TreeNode *root, int k)
{
    TreeNode *curr = root;
    int ans = INT_MAX;
    while (!curr)
    {
        if (abs(curr->val - k) < abs(ans - k))
        {
            ans = curr->val;
        }
        if (curr->val == k)
        {
            return ans;
        }
        else if (k < curr->val)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
    return ans;
}