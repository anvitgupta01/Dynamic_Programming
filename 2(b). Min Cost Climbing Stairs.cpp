// https://www.geeksforgeeks.org/problems/min-cost-climbing-stairs/1

#include <iostream>
#include <vector>
using namespace std;

// Approach :
// Min cost to reach nth step will be minimum of reaching (n-1)th and (n-2)th step; Note that here we do not add the cost of nth step, as we will not go somewhere then.
// Note that cost vector will be of length n, it also does not contain the cost of index = n, as it is not required.
int minCostClimbingStairs(vector<int> &cost, int N)
{
    if (N == 1)
        return cost[0];
    int prev1 = cost[0];
    int prev2 = cost[1];
    for (int i = 2; i < N; i++)
    {
        int temp = cost[i] + min(prev1, prev2);
        prev1 = prev2;
        prev2 = temp;
    }
    return min(prev1, prev2);
}