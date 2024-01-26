// https://www.geeksforgeeks.org/problems/get-minimum-squares0538/1

#include <iostream>
#include <vector>
using namespace std;

// Memoization
int solve(int n, vector<int> &dp)
{
    if (n == 0 || n == 1)
        return n;
    if (dp[n] != -1)
        return dp[n];

    int ans = INT_MAX;
    for (int i = 1; i * i <= n; i++)
    {
        ans = min(ans, 1 + solve(n - i * i, dp));
    }
    return dp[n] = ans;
}
int MinSquares(int n)
{
    vector<int> dp(n + 1, -1);
    int ans = solve(n, dp);
    return ans;
}

// Tabulation
int MinSquares(int n)
{
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    dp[1] = 1;

    for (int t = 2; t <= n; t++)
    {
        dp[t] = INT_MAX;
        for (int i = 1; i * i <= t; i++)
        {
            if (t >= i * i)
                dp[t] = min(dp[t], 1 + dp[t - i * i]);
        }
    }

    return dp[n];
}