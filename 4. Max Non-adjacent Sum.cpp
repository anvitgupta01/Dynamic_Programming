// https://www.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1
// https://www.geeksforgeeks.org/problems/stickler-theif-1587115621/1

#include <iostream>
#include <vector>
using namespace std;

// Memoization
int solve(int *arr, int n, int idx, vector<int> &dp)
{
    if (idx >= n)
        return 0;
    if (dp[idx] != -1)
        return dp[idx];
    int include = arr[idx] + solve(arr, n, idx + 2, dp);
    int exclude = solve(arr, n, idx + 1, dp);
    return dp[idx] = max(include, exclude);
}
int findMaxSum(int *arr, int n)
{
    vector<int> dp(n, -1);
    int ans = solve(arr, n, 0, dp);
    return ans;
}

// Tabulation : Bottom-up approach
int findMaxSum(int *arr, int n)
{
    vector<int> dp(n + 1, 0);
    dp[n - 1] = max(0, arr[n - 1]);

    for (int idx = (n - 2); idx >= 0; idx--)
    {
        dp[idx] = max(dp[idx + 1], dp[idx + 2] + arr[idx]);
    }

    return dp[0];
}

// Space Optimised
int findMaxSum(int *arr, int n)
{
    int prev1 = 0;
    int prev2 = arr[n - 1];

    for (int idx = (n - 2); idx >= 0; idx--)
    {
        int curr = max(prev2, prev1 + arr[idx]);
        prev1 = prev2;
        prev2 = curr;
    }

    return prev2;
}