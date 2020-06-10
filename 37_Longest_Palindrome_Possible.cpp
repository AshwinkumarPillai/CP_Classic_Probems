class Solution
{
public:
    int longestPalindrome(string s)
    {
        int len = 0;
        int odd = 0;
        int maxodd = 0;
        unordered_map<char, int> m;
        for (char x : s)
        {
            m[x]++;
        }

        for (auto p : m)
        {
            if (p.second % 2 == 0)
            {
                len += p.second;
            }
            else
            {
                odd += p.second - 1;
                maxodd = max(odd + 1, maxodd);
            }
        }
        int val = (maxodd < 1) ? 0 : 1;
        return (len + odd + val);
    }
};