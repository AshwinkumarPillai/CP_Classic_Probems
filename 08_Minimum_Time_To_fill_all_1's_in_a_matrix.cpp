// Given a matrix of size N consisting of 0‘s and 1‘s, the task is to find the minimum time required
// to fill the entire matrix with 1‘s. Every 1 at an instant in the matrix, can convert all 0‘s to 1
// in its eight adjacent cells, i.e. a 1 present at (i,j) can convert all 0‘s to 1 at positions
// (i, j-1), (i, j+1), (i-1, j), (i+1, j), (i-1, j-1), (i-1, j+1), (i+1, j-1), (i+1, j+1).

bool checkBoundary(int i, int j, int r, int c)
{
    return i >= 0 && i < r && j >= 0 && j < c;
}

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
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {1, 1}, {-1, 1}, {-1, -1}, {-1, 1}};
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

            for (auto dir : dirs)
            {
                if (checkBoundary(i + dir.first, j + dir.second, r, c) && matrix[i + dir.first][j + dir.second] == 0)
                {
                    q.push({i + dir.first, j + dir.second});
                    matrix[i + dir.first][j + dir.second] = 1;
                }
            }
            steps++;
        }
    }
    return steps;
}