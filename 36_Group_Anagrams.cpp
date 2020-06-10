// Given an array of strings group all the anagram strings together.

vector<vector<string>> groupAnagrams(vector<string> &s)
{
    vector<vector<string>> ans;
    unordered_map<string, vector<int>> m;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        string x = s[i];
        sort(x.begin(), x.end());
        m[x].emplace_back(i);
    }

    for (auto p : m)
    {
        vector<string> sub;
        for (int x : p.second)
        {
            sub.emplace_back(s[x]);
        }
        ans.push_back(sub);
    }
    return ans;
}