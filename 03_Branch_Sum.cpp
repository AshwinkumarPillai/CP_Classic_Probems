// Given a binary tree give the sum of all branches. (A branch is path from root to leaf node).
// Time - O(n) Space - O(n)
void dfs(TreeNode *root, int sum, vector<int> &ans)
{
    if (!root)
    {
        return;
    }
    sum += root->val;
    if (root->left == NULL && root->right == NULL)
    {
        ans.emplace_back(sum);
        // sum -= root->val;
        return;
    }
    dfs(root->left, sum, ans);
    dfs(root->right, sum, ans);
    // sum -= root->val;
    return;
}

vector<int> BranchSum(TreeNode *root)
{
    vector<int> ans;
    dfs(root, 0, ans);
    return ans;
}