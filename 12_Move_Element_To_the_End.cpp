// Given an array and an integer k, move all the instances of k in array to the back of the array.

void moveToEnd(vector<int> &arr, int k)
{
    int n = arr.size();
    int i = 0;
    int j = n - 1;
    while (i < j)
    {
        while (arr[j] == k)
        {
            j--;
        }
        if (j <= i)
        {
            break;
        }
        if (arr[i] == k)
        {
            arr[i] = arr[j];
            arr[j] = k;
        }
        i++;
    }
}