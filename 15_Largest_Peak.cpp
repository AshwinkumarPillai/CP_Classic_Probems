// Find the length of the largest peak
// Time - O(n) Space - O(1)

pair<int, int> calcLength(vector<int> &arr, int i)
{
    int len = 3;
    int l = i - 1, r = i + 1;
    while (arr[l] > arr[l - 1])
    {
        l--;
        len++;
    }

    while (arr[r] > arr[r + 1])
    {
        r++;
        len++;
    }
    return {len, r};
}

int largestPeak(vector<int> &arr)
{
    int sz = INT_MIN;
    for (int i = 1; i < (int)arr.size() - 1; i++)
    {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
        {
            auto p = calcLength(arr, i);
            sz = max(sz, p.first);
            i = p.second;
        }
    }
    return sz;
}