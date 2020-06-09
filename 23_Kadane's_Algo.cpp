// KADANE's ALGO

int maxSumSubarray(vector<int> &arr)
{
    int gmax = INT_MIN;
    int cmax = arr[0];
    for (int i = 1; i < (int)arr.size(); i++)
    {
        cmax = max(cmax, cmax + arr[i]);
        gmax = max(gmax, cmax);
    }
    return gmax;
}