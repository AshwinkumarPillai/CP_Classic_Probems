// Traverse a matrix in spiral manner.

vector<int> spiralTraverse(vector<vector<int>> &matrix)
{
    vector<int> ans;
    int r1 = 0, r2 = matrix.size() - 1, c1 = 0, c2 = matrix[0].size() - 1;
    while (r1 <= r2 && c1 <= c2)
    {
        for (int i = c1; i <= c2; i++)
        {
            ans.emplace_back(matrix[r1][i]);
        }
        for (int i = r1 + 1; i <= r2; i++)
        {
            ans.emplace_back(matrix[i][c2]);
        }
        for (int i = c2 - 1; i >= c1; i--)
        {
            ans.emplace_back(matrix[r2][i]);
        }
        for (int i = r2 - 1; i > r1; i--)
        {
            ans.emplace_back(matrix[i][c1]);
        }

        r1++;
        r2--;
        c1++;
        c2--;
    }
    return ans;
}

// Using recursion
void spiralTraverse(vector<vector<int>> &matrix, int r1, int r2, int c1, int c2, vector<int> &ans)
{
    if (r1 > r2 || c1 > c2)
        return;
    for (int i = c1; i <= c2; i++)
    {
        ans.emplace_back(matrix[r1][i]);
    }
    for (int i = r1 + 1; i <= r2; i++)
    {
        ans.emplace_back(matrix[i][c2]);
    }
    for (int i = c2 - 1; i >= c1; i--)
    {
        ans.emplace_back(matrix[r2][i]);
    }
    for (int i = r2 - 1; i > r1; i--)
    {
        ans.emplace_back(matrix[i][c1]);
    }
    spiralTraverse(matrix, r1 + 1, r2 - 1, c1 + 1, c2 - 1, ans);
}
