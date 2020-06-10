// Given a string S of length N consisting of lower case character, the task is to find the minimum cost to reach from index i to index j.
// At any index k, the cost to jump to the index k+1 and k-1(without going out of bounds) is 1.
// Additionally, the cost to jump to any index m such that S[m] = S[k] is 0.

int minCost(string s, int index1, int index2)
{

    //Actual graph
    vector<vector<int>> graph(26);

    // Adjacency matrix
    vector<vector<bool>> matrix(26, vector<bool>(26, false));

    for (int i = 0; i < (int)s.length(); i++)
    {
        if (i > 0 && !matrix[s[i] - 'a'][s[i - 1] - 'a'])
        {
            graph[s[i] - 'a'].emplace_back(s[i - 1] - 'a');
            matrix[s[i] - 'a'][s[i - 1] - 'a'] = true;
        }
        if (i < s.length() - 1 && !matrix[s[i] - 'a'][s[i + 1] - 'a'])
        {
            graph[s[i] - 'a'].emplace_back(s[i + 1] - 'a');
            matrix[s[i] - 'a'][s[i + 1] - 'a'] = true;
        }
    }

    queue<int> q;
    q.push(s[index1] - 'a');
    vector<int> visited(26);
    int steps = 0;

    while (!q.empty())
    {
        int qs = q.size();
        while (qs--)
        {
            int node = q.front();
            q.pop();
            if (visited[node] == 0)
            {
                visited[node] = 1;
                if (node == s[index2] - 'a')
                {
                    return steps;
                }

                for (int x : graph[node])
                {
                    q.push(x);
                }
            }
        }
        steps++;
    }
    return -1;
}