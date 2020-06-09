// check whether the given array is monotonic.
// Monotonic - increasing or decreasing (elements can be equal to each other).

// Easy to handle - check for opposite
bool isMonotonic(vector<int> &arr)
{
    bool notup = true;
    bool notdown = true;
    for (int i = 1; i < (int)arr.size(); i++)
    {
        if (arr[i] < arr[i - 1])
        {
            notup = false;
        }
        else if (arr[i] > arr[i - 1])
        {
            notdown = false;
        }
    }
    return notup || notdown;
}

// Naive solution (with direction) Time - O(n) Space - O(1)
bool isMonotonic(vector<int> &arr)
{
    if (arr.size() <= 2)
    {
        return true;
    }
    int dir = 0;
    for (int i = 1; i < int(arr.size()); i++)
    {
        if (dir == 0)
        {
            if (arr[i] < arr[i - 1])
            {
                dir = -1;
            }
            else if (arr[i] > arr[i - 1])
            {
                dir = 1;
            }
        }
        else if (dir == 1)
        {
            if (arr[i] < arr[i - 1])
            {
                return false;
            }
        }
        else
        {
            if (arr[i] > arr[i - 1])
            {
                return false;
            }
        }
    }
    return true;
}