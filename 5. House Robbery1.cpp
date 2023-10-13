/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
*/

/*
Hints :
1. Same as Max_Non_Adjacent_Sum problem in dp
*/
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> v)
{
    int n = v.size();
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return v[0];
    }

    int prev1 = v[0];
    int prev2 = max(v[0], v[1]);
    for (int i = 2; i < n; i++)
    {
        int ans = max(prev2, prev1 + v[i]);
        prev1 = prev2;
        prev2 = ans;
    }
    return prev2;
}

int rob(vector<int> &nums)
{
    return solve(nums);
}