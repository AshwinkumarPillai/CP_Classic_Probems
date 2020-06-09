// Given a Binary Search Tree, implement the following functions:
// Insertion, Deletion, Searching of a node.

int removeSmallest(TreeNode *root)
{
    if (root->left == NULL && root->right == NULL)
    {
        int val = root->val;
        root = NULL;
        return val;
    }
    if (root->left == NULL)
    {
        return removeSmallest(root->right);
    }
    return removeSmallest(root->left);
}

// Time - O(log(n)) Space - O(1)
void insertNode(TreeNode *root, int val)
{
    TreeNode *trav = root;
    while (1)
    {
        if (val < trav->val)
        {
            if (!trav->left)
            {
                trav->left = new TreeNode(val);
                break;
            }
            else
            {
                trav = trav->left;
            }
        }
        else
        {
            if (!trav->right)
            {
                trav->right = new TreeNode(val);
                break;
            }
            else
            {
                trav = trav->right;
            }
        }
    }
}

void deleteNode(TreeNode *root, int val)
{
    TreeNode *trav = root;
    TreeNode *parent = NULL;
    int side = 0;
    while (trav != NULL)
    {
        if (val < trav->val)
        {
            parent = trav;
            side = -1;
            trav = trav->left;
        }
        else if (val > trav->val)
        {
            parent = trav;
            side = 1;
            trav = trav->right;
        }
        else
        {
            if (trav->left != NULL && trav->right != NULL)
            {
                trav->val = removeSmallest(trav->right);
                break;
            }
            else if (trav->left == NULL && trav->right == NULL)
            {
                trav = NULL;
                break;
            }
            else if (trav->left == NULL)
            {
                if (side == -1)
                {
                    parent->left = trav->right;
                }
                else if (side == 1)
                {
                    parent->right = trav->right;
                }
                break;
            }
            else
            {
                if (side == -1)
                {
                    parent->left = trav->left;
                }
                else if (side == 1)
                {
                    parent->right = trav->left;
                }
                break;
            }
        }
    }
}

TreeNode *searchNode(TreeNode *root, int val)
{
    TreeNode *trav = root;
    TreeNode *ans;
    while (trav != NULL)
    {
        if (val < trav->val)
        {
            trav = trav->left;
        }
        else if (val > trav->val)
        {
            trav = trav->right;
        }
        else
        {
            return trav;
        }
    }
    return ans;
}