// Given a sorted matrix, find the given integer in it and return the indices.

pair<int, int> SearchSortedMatrix(vector<vector<int>> &matrix, int k)
{
    int r = matrix.size();
    if (r == 0)
    {
        return {-1, -1};
    }
    int c = matrix[0].size();
    int i = 0, j = c - 1;
    while (i < r && j >= 0)
    {
        if (matrix[i][j] == k)
        {
            return {i, j};
        }
        else if (matrix[i][j] > k)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return {-1, -1};
}