// Find the LCA such that we can only access the parents with parent pointer.

int calcDepth(TreeNode *root, TreeNode *trav)
{
    int d = 0;
    while (trav != root)
    {
        d++;
        trav = trav->parent;
    }
    return d;
}

TreeNode *findParent(TreeNode *lower, TreeNode *higher, int d)
{
    while (d--)
    {
        lower = lower->parent;
    }
    while (lower != higher)
    {
        lower = lower->parent;
        higher = higher->parent;
    }
    return lower;
}

TreeNode *yca(TreeNode *node1, TreeNode *node2, TreeNode *root)
{
    int depth1 = calcDepth(root, node1);
    int depth2 = calcDepth(root, node2);
    int d = abs(depth1 - depth2);
    if (depth1 > depth2)
    {
        return findParent(node2, node1, d);
    }
    return findParent(node1, node2, d);
}
