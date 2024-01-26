// https://www.geeksforgeeks.org/problems/dearrangement-of-balls0918/1

#include <iostream>
using namespace std;
typedef long long ll;

// F(n) = (F(n-1)+F(n-2))*(n-1)
long int disarrange(int N)
{
    if (N == 1 || N == 2)
        return N - 1;

    ll prev1 = 0;
    ll prev2 = 1;
    const int mod = 1000000007;

    for (int i = 3; i <= N; i++)
    {
        ll temp = (((prev1 + prev2) % mod) * (i - 1)) % mod;
        prev1 = prev2 % mod;
        prev2 = temp;
    }

    return prev2 % mod;
}