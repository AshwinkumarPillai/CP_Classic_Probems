// Given a matrix of size N consisting of 0‘s and 1‘s, the task is to find the minimum time required
// to fill the entire matrix with 1‘s. Every 1 at an instant in the matrix, can convert all 0‘s to 1
// in its eight adjacent cells, i.e. a 1 present at (i,j) can convert all 0‘s to 1 at positions
// (i, j-1), (i, j+1), (i-1, j), (i+1, j), (i-1, j-1), (i-1, j+1), (i+1, j-1), (i+1, j+1).

int numOfSteps(vector<vector<int>> &matrix)
{
    queue<pair<int, int>> q;
    int r = matrix.size();
    int c = matrix[0].size();
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            q.push({i, j});
        }
    }
    int steps = 0;

    // BFS
    while (!q.empty())
    {
        int csize = q.size();
        while (csize--)
        {
            pair<int, int> p = q.front();
            q.pop();
            int i = p.first;
            int j = p.second;

            if ((j > 0) && matrix[i][j - 1] == 0)
            {
                q.push({i, j - 1});
                matrix[i][j - 1] = 1;
            }
            if (i < n - 1 && matrix[i + 1][j] == 0)
            {
                matrix[i + 1][j] = 1;
                q.push({i + 1, j});
            }
            if ((j < n - 1) && matrix[i][j + 1] == 0)
            {
                matrix[i][j + 1] = 1;
                q.push({i, j + 1});
            }
            if ((i > 0) && matrix[i - 1][j] == 0)
            {
                matrix[i - 1][j] = 1;
                q.push({i - 1, j});
            }
            if ((i > 0) && (j > 0) &&
                matrix[i - 1][j - 1] == 0)
            {
                matrix[i - 1][j - 1] = 1;
                q.push({i - 1, j - 1});
            }
            if ((i > 0) && (j < (n - 1)) &&
                matrix[i - 1][j + 1] == 0)
            {
                matrix[i - 1][j + 1] = 1;
                q.push({i - 1, j + 1});
            }
            if ((i < (n - 1)) && (j < (n - 1)) &&
                matrix[i + 1][j + 1] == 0)
            {
                matrix[i + 1][j + 1] = 1;
                q.push({i + 1, j + 1});
            }
            if ((i < (n - 1)) && (j > 0) &&
                matrix[i + 1][j - 1] == 0)
            {
                matrix[i + 1][j - 1] = 1;
                q.push({i + 1, j - 1});
            }
            steps++;
        }
    }
    return steps;
}