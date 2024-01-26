// https://www.geeksforgeeks.org/problems/number-of-coins1824/1

#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &coins, int M, int v, vector<int> &dp)
{
    if (v < 0)
        return INT_MAX;
    if (v == 0)
        return dp[v] = 0;
    if (dp[v] != -1)
        return dp[v];
    int mini = INT_MAX;
    for (int i = 0; i < M; i++)
    {
        int anse = solve(coins, M, v - coins[i], dp);
        if (anse != INT_MAX)
        {
            mini = min(mini, anse + 1);
        }
    }
    return dp[v] = mini;
}
int minCoins(vector<int> &coins, int M, int V)
{
    vector<int> dp(V + 1, -1);
    int ans = solve(coins, M, V, dp);
    if (ans == INT_MAX)
        return -1;
    return ans;
}