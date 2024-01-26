// https://www.codingninjas.com/studio/problems/number-of-ways_3755252

#include <iostream>
#include <vector>
using namespace std;

// Memoization
int solve(vector<int> &num, int tar, vector<int> &dp)
{
    if (tar == 0)
        return 1;
    if (tar < 0)
        return 0;
    if (dp[tar] != -1)
        return dp[tar];

    int ans = 0;
    for (int i = 0; i < num.size(); i++)
    {
        ans += solve(num, tar - num[i], dp);
    }
    return dp[tar] = ans;
}
int findWays(vector<int> &num, int tar)
{
    vector<int> dp(tar + 1, -1);
    int ans = solve(num, tar, dp);
    return ans;
}

// Tabulation: Good approach : See that dp[tar]=ans is made after summing up all the i's... hence i loop will be the inner loop...
int findWays(vector<int> &num, int tar)
{
    vector<int> dp(tar + 1, 0);
    dp[0] = 1;
    int n = num.size();

    for (int t = 1; t <= tar; t++)
    {
        for (int i = 0; i < n; i++)
        {
            if (t >= num[i])
                dp[t] += dp[t - num[i]];
        }
    }

    return dp[tar];
}