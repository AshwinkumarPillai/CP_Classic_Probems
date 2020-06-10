// Find the length of the largets palindromic substring

int findLength(string &s, int l, int r)
{
    int n = s.length();
    while (l >= 0 && r < n && s[l] == s[r])
    {
        l--;
        r++;
    }
    return r - l - 1;
}

int LongestPalindromicSubstring(string &s)
{
    int best = 1;
    int n = s.length();
    for (int i = 1; i < n; i++)
    {
        int odd = findLength(s, i - 1, i + 1);
        int even = findLength(s, i - 1, i);
        best = max({odd, even, best});
    }
    return best;
}

// If we have to return the string then =>

pair<int, int> findLength(string &s, int l, int r)
{
    int n = s.length();
    while (l >= 0 && r < n && s[l] == s[r])
    {
        l--;
        r++;
    }
    return {l + 1, r - l - 1};
}

string LongestPalindromicSubstring(string &s)
{
    int best = 1;
    int start = 0;
    int n = s.length();
    if (n == 0 || n == 1)
    {
        return s;
    }
    for (int i = 1; i < n; i++)
    {
        auto odd = findLength(s, i - 1, i + 1);
        auto even = findLength(s, i - 1, i);
        if (odd.second >= even.second)
        {
            if (odd.second > best)
            {
                best = odd.second;
                start = odd.first;
            }
        }
        else
        {
            if (even.second > best)
            {
                best = even.second;
                start = even.first;
            }
        }
    }
    return s.substr(start, best);
}