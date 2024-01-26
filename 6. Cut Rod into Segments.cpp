// https://www.geeksforgeeks.org/problems/cutted-segments1642/1

#include <iostream>
#include <vector>
using namespace std;

// Memoization
int solve(int n, int x, int y, int z, vector<int> &dp)
{
    if (n < 0)
        return INT_MIN;
    if (n == 0)
        return dp[n] = 0;
    if (dp[n] != -1)
        return dp[n];

    int x1 = solve(n - x, x, y, z, dp);
    int x2 = solve(n - y, x, y, z, dp);
    int x3 = solve(n - z, x, y, z, dp);

    return dp[n] = (1 + max(x1, max(x2, x3)));
}
int maximizeTheCuts(int n, int x, int y, int z)
{
    vector<int> dp(n + 1, -1);
    int ans = solve(n, x, y, z, dp);
    if (ans < 0)
        return 0;
    return ans;
}

// Tabulation
int maximizeTheCuts(int n, int x, int y, int z)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = INT_MIN;
        if (i >= x)
            dp[i] = max(dp[i], dp[i - x]);
        if (i >= y)
            dp[i] = max(dp[i], dp[i - y]);
        if (i >= z)
            dp[i] = max(dp[i], dp[i - z]);
        dp[i] += 1;
    }

    if (dp[n] < 0)
        return 0;
    return dp[n];
}
