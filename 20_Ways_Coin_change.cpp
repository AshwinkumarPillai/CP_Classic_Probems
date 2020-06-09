// Coin change II (LEETCODE)

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        int m = coins.size();
        if (amount == 0)
        {
            return 1;
        }
        vector<vector<int>> dp(m + 1, vector<int>(amount + 1));
        for (int i = 0; i <= m; i++)
        {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= amount; j++)
            {
                int x = coins[i - 1];
                if (x > j)
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - x];
                }
            }
        }
        return dp[m][amount];
    }
};