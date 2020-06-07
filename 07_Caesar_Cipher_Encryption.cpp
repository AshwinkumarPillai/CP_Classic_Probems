// Given an input string and an integer, change every character in the string to the character + k.
// Example => s =  abc; k =2; --> s = cde | s = xyz; k=3 --> s = abc

void Cipher(string &s, int k)
{
    k = k % 26;
    for (int i = 0; i < (int)s.length(); i++)
    {
        int x = s[i] + k;
        x = 'a' + x % 'z' - 1;
        cout << x << "\n";
        s[i] = x;
    }
}