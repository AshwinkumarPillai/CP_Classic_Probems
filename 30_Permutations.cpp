// Give all permmutations of given array.

void swap(vector<int> &arr, int i, int j)
{

    int temp = arr[j];
    arr[j] = arr[i];
    arr[i] = temp;
}

void Permute(vector<int> arr, int i, vector<vector<int>> &ans, int n)
{
    if (i == n)
    {
        ans.push_back(arr);
    }
    else
    {
        for (int j = i; j <= n; j++)
        {
            swap(arr, i, j);
            Permute(arr, i + 1, ans, n);
            swap(arr, i, j);
        }
    }
}

vector<vector<int>> Permutations(vector<int> &arr)
{
    vector<vector<int>> ans;
    Permute(arr, 0, ans, (int)arr.size() - 1);
    return ans;
}

// Space expensive method ===========================================================

vector<int> getNewArr(vector<int> arr, int i)
{
    vector<int> re;
    for (int j = 0; j < i; j++)
    {
        re.empalce_back(arr[j]);
    }
    for (int j = i + 1; j < (int)arr.size(); j++)
    {
        re.emplace_back(arr[j]);
    }
    return re;
}

void Permute(vector<int> &arr, vector<int> currentPerm, vector<vector<int>> &ans)
{
    if ((int)arr.size() == 0 && (int)ans.size() != 0)
    {
        ans.push_back(currentPerm);
    }
    else
    {
        for (int i = 0; i < (int)arr.size(); i++)
        {
            newarr = getNewArr(arr, i);
            vector<int> newPermutation = currentPerm;
            newPermutation.push_back(arr[i]);
            Permute(newarr, newPermutation, ans);
        }
    }
}

vector<vector<int>> Permutations(vector<int> &arr)
{
    vector<vector<int>> ans;
    Permute(arr, 0, ans, (int)arr.size() - 1);
    return ans;
}