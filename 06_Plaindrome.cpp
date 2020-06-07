// Self Explanotary Question.

bool isPalindrome(string s)
{
    int n = s.length() - 1;
    int i = 0;
    while (i <= n)
    {
        if (s[i++] != s[n--])
        {
            return false;
        }
    }
    return true;
}