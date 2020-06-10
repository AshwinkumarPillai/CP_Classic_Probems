// Given a stack implement functionality of giving the maximum and minimum value at given time and peek the top element.

class MinMaxStack
{
public:
    vector<pair<int, int>> minmax;
    vector<int> s;

    int getMin()
    {
        if ((int)s.size() == 0)
            return -1;
        return minmax.back().first;
    }

    int getMax()
    {
        if ((int)s.size() == 0)
            return -1;
        return minmax.back().second;
    }

    int peek()
    {
        if ((int)s.size() == 0)
            return -1;
        return s.back();
    }

    void push(int x)
    {
        if ((int)s.size() == 0)
        {
            s.push_back(x);
            minmax.push_back({x, x});
            return;
        }
        s.push_back(x);
        auto p = minmax.back();
        int a = min(x, p.first);
        int b = max(x, p.second);
        minmax.push_back({a, b});
    }

    void pop()
    {
        if ((int)s.size() == 0)
        {
            return;
        }
        s.pop_back();
        minmax.pop_back();
    }
}