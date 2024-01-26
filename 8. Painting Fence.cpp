// https://www.geeksforgeeks.org/problems/painting-the-fence3727/1

#include <iostream>
using namespace std;

typedef long long ll;

// Using const int will give wrong ans...
const long long mod = 1000000007;
class Solution
{
public:
    long long countWays(int n, int k)
    {
        ll prev1 = k;
        ll prev2 = ((k % mod) * (k % mod)) % mod;
        if (n == 1)
            return k;
        for (int i = 3; i <= n; i++)
        {
            ll temp = ((k - 1) % mod * (prev1 + prev2)) % mod;
            prev1 = prev2 % mod;
            prev2 = temp;
        }
        return prev2 % mod;
    }
};
