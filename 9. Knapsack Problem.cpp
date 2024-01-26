// https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

#include <iostream>
#include <vector>
using namespace std;

// Memoization
int solve(vector<pair<int, int>> &vp, int idx, int n, int W, vector<vector<int>> &dp)
{
    if (W == 0)
        return 0;
    if (W < 0)
        return INT_MIN;
    if (idx >= n)
        return 0;
    if (dp[idx][W] != -1)
        return dp[idx][W];

    int include = solve(vp, idx + 1, n, W - vp[idx].first, dp);
    int exclude = solve(vp, idx + 1, n, W, dp);

    if (include != INT_MIN)
        include += vp[idx].second;
    else
        include = 0;

    return dp[idx][W] = max(include, exclude);
}
int knapSack(int W, int wt[], int val[], int n)
{
    vector<pair<int, int>> vp;
    for (int i = 0; i < n; i++)
    {
        vp.push_back({wt[i], val[i]});
    }
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    int ans = solve(vp, 0, n, W, dp);
    if (ans < 0)
        return 0;
    return ans;
}

// Tabulation
int knapSack(int W, int wt[], int val[], int n)
{
    vector<pair<int, int>> vp;
    for (int i = 0; i < n; i++)
    {
        vp.push_back({wt[i], val[i]});
    }
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int idx = (n - 1); idx >= 0; idx--)
    {
        for (int w = 1; w <= W; w++)
        {
            dp[idx][w] = dp[idx + 1][w];
            if (w >= vp[idx].first)
                dp[idx][w] = max(dp[idx][w], dp[idx + 1][w - vp[idx].first] + vp[idx].second);
        }
    }
    return dp[0][W];
}

// Space optimised
int knapSack(int W, int wt[], int val[], int n)
{
    vector<pair<int, int>> vp;
    for (int i = 0; i < n; i++)
    {
        vp.push_back({wt[i], val[i]});
    }

    vector<int> prev(W + 1, 0);

    for (int idx = (n - 1); idx >= 0; idx--)
    {
        vector<int> curr(W + 1, 0);
        for (int w = 1; w <= W; w++)
        {
            curr[w] = prev[w];
            if (w >= vp[idx].first)
                curr[w] = max(curr[w], prev[w - vp[idx].first] + vp[idx].second);
        }
        prev = curr;
    }
    return prev[W];
}