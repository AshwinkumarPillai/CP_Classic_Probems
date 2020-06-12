// Parenthesis Theorem is used in DFS of graph. It states that the descendants in a depth-first-search tree have an interesting property. If v is a descendant of u, then the discovery time of v is later than the discovery time of u.
// In any DFS traversal of a graph g = (V, E), for any two vertices u and v exactly one of the following holds:

// The intervals [d[u], f[u]] and [d[v], f[v]] are entirely disjoint and u nor v is a descendant of the other in the depth-first forest.
// The interval [d[u], f[u]] is contained within the interval [d[v], f[v]], and u is a descendant of v in a depth-first tree.
// The interval [d[u], f[u]] is contained entirely within the interval [d[v], f[v]], and v is a descendant of u in a depth-first tree

// Tree Edge: For any Edge (U, V), if node U is the parent of node V, then (U, V) is the Tree Edge of the given graph.
// Forward Edge: For any Edge (U, V), if discovery time and finishing time of node V fully overlaps with discovery time and finishing time of node U, then (U, V) is the Forward Edge of the given graph.
// Backward Edge: For any Edge (U, V), if discovery time and finishing time of node U fully overlaps with discovery time and finishing time of node V, then (U, V) is the Backward Edge of the given graph.
// Cross Edge: For any Edge (U, V), if discovery time and finishing time of node U doesn’t overlaps with discovery time and finishing time of node V, then (U, V) is the Cross Edge of the given graph.

int currentTime = 0;
vector<int> startTime, finTime;
vector<int> parent;

void dfs(map<int, vector<int>> &m, vector<int> &visited, int i)
{
    if (visited[i] == 1)
    {
        return;
    }
    visited[i] = 0;
    startTime[i] = currentTime++;
    for (int x : m[i])
    {
        if (visited[x] == -1)
        {
            parent[x] = i;
            dfs(m, visited, x);
        }
    }
    finTime[i] = currentTime++;
    visited[i] = 1;
}

string typeOfEdge(map<int, vector<int>> &m, int i, int j)
{
    if (parent[j] == i)
    {
        return "Tree Edge";
    }
    int st1 = startTime[i], st2 = startTime[j], fin1 = finTime[i], fin2 = finTime[j];
    if ((st2 > st1) && (fin1 > fin2))
    {
        return "Forward Edge";
    }
    else if ((st1 > st2) && (fin1 < fin2))
    {
        return "Backward Edge";
    }
    return "Cross Edge";
}

void EdgeClassification(vector<vector<int>> &edges, int n)
{
    map<int, vector<int>> m;
    vector<int> visited(n + 1, -1); // (-1) ->not visted | 0 -> visiting | 1 ->  completely visited
    parent.resize(n + 1);
    startTime.resize(n + 1);
    finTime.resize(n + 1);
    for (auto x : edges)
    {
        m[x[0]].push_back(x[1]);
        m[x[1]].push_back(x[0]);
    }

    for (auto p : m)
    {
        if (visited[p.first] == -1)
        {
            dfs(m, visited, p.first);
        }
    }

    for (auto x : edges)
    {
        cout << "(" << x[0] << ", " << x[1] << ") => " << typeOfEdge(m, x[0], x[1]) << "\n";
    }
}