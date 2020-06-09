// Classic DP problem - Min coin change

int minCoinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1));

    for (int i = 1; i <= n; i++)
    {
        int x = coins[i - 1];
        for (int j = 1; j <= amount; j++)
        {
            if (x > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - x]);
            }
        }
    }
    return dp[n][amount];
}