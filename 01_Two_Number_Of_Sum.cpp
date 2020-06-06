// Given an array arr and an integer k return the indices of the numbers in the array whose sum is k.

// HashMap approach Time - O(n) Space - O(n)

pair<int, int> twoNumberSum(vector<int> arr, int k)
{
    map<int, int> m;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (m.find(k - arr[i]) != m.end())
        {
            return {i, m[k - arr[i]]};
        }
        else
        {
            m[arr[i]] = i;
        }
    }
    return {-1, -1};
}

// Two pointer approach Time - O(nlogn) + O(n) Space - O(1)

pair<int, int> twoNumberSum(vector<int> arr, int k)
{
    int i = 0, j = arr.size() - 1;
    sort(arr.begin(), arr.end())
    {
        int sum = arr[i] + arr[j];
        if (sum == k)
        {
            return {i, j};
        }
        else if (sum < k)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return {-1, -1};
}