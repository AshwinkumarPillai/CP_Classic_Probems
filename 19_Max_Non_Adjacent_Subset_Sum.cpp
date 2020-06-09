// Given an array, find the maximum subset sum such that the elements considered for sum are not adjacent.

// Space Efficient O(1)
int maxSubsetSumNonAdjacent(vector<int> &arr)
{
    int prev = arr[0];
    int ans = max(arr[0], arr[1]);
    for (int i = 2; i < n; i++)
    {
        int temp = prev;
        prev = ans;
        ans = max(ans, temp + arr[i]);
    }
    return ans;
}

// TIme - O(n) Space - O(n)
int maxSubsetSumNonAdjacent(vector<int> &arr)
{
    vector<int> ans;
    ans.emplace_back(arr[0]);
    ans.emplace_back(max(arr[0], arr[1]));
    for (int i = 2; i < (int)arr.size(); i++)
    {
        ans.emplace_back(max(ans[i - 1], ans[i - 2] + arr[i]));
    }
    return ans.back();
}