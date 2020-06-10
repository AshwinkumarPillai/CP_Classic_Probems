// Given an array generate the powerset of the array.
// power set of [1,2] = [[],[1],[2],[1,2]]

// Iterative approach
vector<vector<int>> powerSet(vector<int> &num_set)
{
    int n = num_set.size();
    vector<vector<int>> ans;
    ans.push_back({});
    for (int x : num_set)
    {
        int n = ans.size();
        for (int i = 0; i < n; i++)
        {
            vector<int> temp = ans[i];
            temp.push_back(x);
            ans.push_back(temp);
        }
    }
    return ans;
}
