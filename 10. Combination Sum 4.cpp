#include <bits/stdc++.h>
using namespace std;

// Recursion :
int distinctWays(vector<int> v, int sum)
{
    if (sum < 0)
    {
        return 0;
    }
    if (sum == 0)
    {
        return 1;
    }
    int ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        ans += distinctWays(v, sum - v[i]);
    }
    return ans;
}

// Recursin + Memoization :
// dp[i] denotes number of ways in which sum = i be created using v:
int solve(vector<int> v, int sum, vector<int> &dp)
{
    if (sum < 0)
    {
        return 0;
    }
    if (sum == 0)
    {
        return 1;
    }

    if (dp[sum] != -1)
    {
        return dp[sum];
    }

    int ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        ans += solve(v, sum - v[i], dp);
    }
    dp[sum] = ans;
    return dp[sum];
}
int distinctWays1(vector<int> v, int sum)
{
    vector<int> dp(sum + 1, -1);
    dp[0] = 1;
    return solve(v, sum, dp);
}

// Tabulation :
int distinctWays2(vector<int> v, int sum)
{
    if (sum < 0)
    {
        return 0;
    }

    vector<int> dp(sum + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= sum; i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            if (i >= v[j])
            {
                dp[i] += dp[i - v[j]];
            }
        }
    }
    return dp[sum];
}

int main()
{
    cout << "Enter the number of distinct numbers given " << endl;
    int n;
    cin >> n;

    vector<int> v(n, -1);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v[i] = x;
    }

    cout << "Enter the sum required " << endl;
    int sum;
    cin >> sum;

    cout << "The different number of ways will be " << distinctWays(v, sum) << endl;
    cout << "The different number of ways will be " << distinctWays1(v, sum) << endl;
    cout << "The different number of ways will be " << distinctWays2(v, sum) << endl;
    return 0;
}