// Given an array return the three largest numbers in the array in ascending order

void updateAns(vector<int> &ans, int x)
{
    int n = ans.size();
    if (x < ans[0])
    {
        return;
    }
    else if (x > ans[2])
    {
        ans[0] = ans[1];
        ans[1] = ans[2];
        ans[2] = x;
    }
    else if (x > ans[1])
    {
        ans[0] = ans[1];
        ans[1] = x;
    }
    else
    {
        ans[0] = x;
    }
}

vector<int> ThreeLargest(vector<int> &arr)
{
    vector<int> ans = {INT_MIN, INT_MIN, INT_MIN};
    for (int x : arr)
    {
        updateAns(ans, x);
    }
    return ans;
}