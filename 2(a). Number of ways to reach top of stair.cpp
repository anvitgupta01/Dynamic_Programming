// https://www.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair-1587115620/1

#include <iostream>
using namespace std;
typedef long long ll;

int countWays(int n)
{
    if (n == 0 || n == 1)
        return 1;
    ll prev1 = 1;
    ll prev2 = 1;
    const int mod = 1000000007;
    for (int i = 2; i <= n; i++)
    {
        ll temp = (prev1 + prev2) % mod;
        prev1 = prev2 % mod;
        prev2 = temp;
    }
    return prev2 % mod;
}