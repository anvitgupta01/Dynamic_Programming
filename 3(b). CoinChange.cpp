// https://www.geeksforgeeks.org/problems/coin-change2448/1

// Knapsack problems :  The problems involving two conditions : either to include or to exclude...
// CoinChange is a kind of knapsack problem...

#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

// Memoization : Top-down Approach
ll solve(int coins[], int N, int sum, int idx, vector<vector<ll>> &dp)
{
    if (sum == 0)
        return 1;
    if (idx >= N || sum < 0)
        return 0;
    if (dp[idx][sum] != -1)
        return dp[idx][sum];

    ll exclude = solve(coins, N, sum, idx + 1, dp);
    ll include = solve(coins, N, sum - coins[idx], idx, dp);

    return dp[idx][sum] = (include + exclude);
}
long long int count(int coins[], int N, int sum)
{
    vector<vector<ll>> dp(N, vector<ll>(sum + 1, -1));
    ll ans = solve(coins, N, sum, 0, dp);
    return ans;
}

// Tabulation : Bottom-up Approach
// idx is increasing and sum is decreasing in memoization, hence it will be reverse in tabulation
long long int count(int coins[], int N, int sum)
{
    vector<vector<ll>> dp(N + 1, vector<ll>(sum + 1, 0));

    for (int i = 0; i <= N; i++)
    {
        dp[i][0] = 1; // if sum is 0
    }

    for (int idx = N - 1; idx >= 0; idx--)
    {
        for (int sump = 1; sump <= sum; sump++)
        {
            dp[idx][sump] = dp[idx + 1][sump];
            if (sump >= coins[idx])
            {
                dp[idx][sump] += dp[idx][sump - coins[idx]];
            }
        }
    }

    return dp[0][sum];
}

// Space Optimised : O(sum)
long long int count(int coins[], int N, int sum)
{
    // This vector is like idx=N and sum varying
    vector<ll> prev(sum + 1, 0);
    prev[0] = 1;

    for (int idx = N - 1; idx >= 0; idx--)
    {
        vector<ll> curr(sum + 1, 0);
        curr[0] = 1;

        for (int sump = 1; sump <= sum; sump++)
        {
            curr[sump] = prev[sump];
            if (sump >= coins[idx])
            {
                curr[sump] += curr[sump - coins[idx]];
            }
        }

        prev = curr;
    }

    return prev[sum];
}