// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.
// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.


#include <iostream>
#include <vector>
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
    if (nums.size() == 0)
    {
        return 0;
    }
    else if (nums.size() == 1)
    {
        return nums[0];
    }

    vector<int> first, last;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i != (nums.size() - 1))
        {
            first.push_back(nums[i]);
        }
        if (i != 0)
        {
            last.push_back(nums[i]);
        }
    }

    return max(solve(first), solve(last));
}

int main(){
    cout<<"Enter the number of houses"<<endl;
    int n;cin>>n;
    cout<<"Enter the value in all the houses"<<endl;
    vector<int> v(n,-1);
    for(int i=0;i<n;i++){
        int x;cin>>x;
        v[i] = x;
    }
    cout<<"Maximum amount of money that the robber can rob is "<<rob(v)<<endl;
    return 0;
}