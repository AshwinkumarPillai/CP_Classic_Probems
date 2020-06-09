// Given a matix (graph)  return an arrya of all river sizes.
// A river is series of 1's adjacent to each other either horizzontally or vertically.

#include <bits/stdc++.h>

using namespace std;

bool checkBoundary(int row, int col, int r, int c)
{
    return (row >= 0) && (col >= 0) && (row < r) && (col < c);
}

int dfs(vector<vector<int>> &matrix, vector<vector<bool>> &visited, int i, int j, int r, int c)
{
    int size = 0;
    queue<pair<int, int>> q;
    q.push({i, j});
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        i = p.first;
        j = p.second;
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        if (!visited[i][j])
        {
            visited[i][j] = true;
            if (matrix[i][j] == 1)
            {
                size++;
                for (auto dir : dirs)
                {
                    if (checkBoundary(i + dir.first, j + dir.second, r, c) && !visited[i + dir.first][j + dir.second] && matrix[i + dir.first][j + dir.second] == 1)
                    {
                        q.push({i + dir.first, j + dir.second});
                    }
                }
            }
        }
    }
    return size;
}

vector<int> riverSizes(vector<vector<int>> &matrix)
{
    vector<int> ans;
    int r = matrix.size();
    int c = matrix[0].size();
    vector<vector<bool>> visited(r, vector<bool>(c, false));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (!visited[i][j])
            {
                int s = dfs(matrix, visited, i, j, r, c);
                if (s > 0)
                {
                    ans.emplace_back(s);
                }
            }
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> matrix = {{1, 0, 0, 1, 0}, {1, 0, 1, 0, 0}, {0, 0, 1, 0, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 0}};
    vector<int> ans = riverSizes(matrix);
    for (int x : ans)
    {
        cout << x << " ";
    }
    return 0;
}