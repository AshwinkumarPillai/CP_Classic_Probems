// Given an array find whether the array consists a single cycle.
// The number in the array defines the rate of jump.
// [2,4,5,6,-1] - Here 2 means we can jump to 5 and from 5 further 5 steps.
// for -1 - one step backward.
// We should visit all the elements in the array exactly one time. - visit the first number to end.
// [2,0,-2,1,-1] - here we have 2 cycles : 2 -2 and 1 -1

// O(1) space - as we should visit all index only one time so total will be n and at the end we should be at starting index.
bool containsCycle(vector<int> &arr)
{
    int nvisited = 0;
    int start = = 0;
    int n = arr.size();
    int index = start;
    while (nvisited < n)
    {
        if (nvisited > 0 && index == start)
        {
            return false;
        }
        nvisited++;
        index = (index + arr[i]) % n;
        if (index < 0)
            index += n;
    }
    return index == start;
}

// Using visited array.
bool containsCycle(vector<int> &arr)
{
    int n = arr.size();
    vector<int> visited(n);
    int i = 0;
    while (true)
    {
        if (visited[i] > 0)
        {
            if (i != 0)
            {
                return false;
            }
            else if (visited[i] == 2)
            {
                for (int x : visited)
                {
                    if (x == 0)
                    {
                        return false;
                    }
                    return true;
                }
            }
        }
        visited[i]++;
        i = (i + arr[i]) % n;
        if (i < 0)
        {
            i += n;
        }
    }
    return true;
}