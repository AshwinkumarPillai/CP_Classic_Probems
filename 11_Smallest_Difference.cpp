// Given Two arrays find the two closest numbers from both arrays.

pair<int, int> SmallestDifference(vector<int> &a, vector<int> &b)
{
    int n = a.size();
    int m = b.size();
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    pair<int, int> ans;
    int diff = INT_MAX;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        int cdiff = abs(a[i] - b[j]);
        if (cdiff < diff)
        {
            diff = cdiff;
            ans = {a[i], b[j]};
        }
        if (cdiff == 0)
        {
            break;
        }
        else if (a[i] < b[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return ans;
}