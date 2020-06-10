// Check if the paranthesis order in given is correct.
#include <bits/stdc++.h>

bool checkBrackets(string &s)
{
    stack<int> st;
    set<char> closed = {'}', ')', ']'};
    map<char, char> m;
    m[']'] = '[';
    m['}'] = '{';
    m[')'] = '(';
    for (char x : s)
    {
        if (closed.find(x) != closed.end())
        {
            if (m[x] != st.top())
            {
                return false;
            }
            st.pop();
        }
        else
        {
            st.push(x);
        }
    }
    return st.size() == 0;
}