// https://leetcode.com/problems/house-robber-ii/description/

#include <iostream>
#include <vector>
using namespace std;

int FindMax(vector<int> &money, int n)
{
    int prev1 = 0;
    int prev2 = money[n - 1];

    for (int i = (n - 2); i >= 0; i--)
    {
        int curr = max(prev2, prev1 + money[i]);
        prev1 = prev2;
        prev2 = curr;
    }

    return prev2;
}

// Include first and exclude last - Case 1
// Include last and exclude first - Case 2
int rob(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return nums[0];

    vector<int> first, last;
    for (int i = 0; i < (n - 1); i++)
    {
        first.push_back(nums[i]);
        last.push_back(nums[i + 1]);
    }

    return max(FindMax(first, n - 1), FindMax(last, n - 1));
}