// Given an array and an integer k, return an array of triplets whose sum is equal to k.

vector<vector<int>> ThreeNumberSum(vector<int> &arr, int k)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    int n = arr.size();
    for (int i = 0; i < n - 2; i++)
    {
        int val = arr[i];
        int l = i + 1;
        int r = n - 1;
        while (l < r)
        {
            int csum = val + arr[l] + arr[r];
            if (csum == k)
            {
                ans.push_back({val, arr[l++], arr[r--]});
            }
            else if (csum < k)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
    }
    return ans;
}