#include <iostream>
#include <vector>
using namespace std;

// Recursive Approach : 
// Min cost to reach nth step will be minimum of reaching (n-1)th and (n-2)th step; Note that here we do not add the cost of nth step, as we will not go somewhere then.
// Note that cost vector will be of length n, it also does not contain the cost of index = n, as it is not required.
int solve(int n,vector<int> cost){
    if(n==0 || n==1){
        return cost[n];
    }
    return min(solve(n-1,cost),solve(n-2,cost)) + cost[n];
}
int MinCost1(int n,vector<int> cost){
    if(n==0 || n==1){
        return 0;
    }
    return min(solve(n-1,cost),solve(n-2,cost));
}


// Dynamic Programming : Top-down Approach : Recursion + Memoization : 
// Time Complexity : O(n)
// Space Complexity : O(2*n)
int solve1(int n,vector<int> cost, vector<int> &dp){
    if(n==0 || n==1){
        return cost[n];
    }
    return dp[n] =( min(solve1(n-1,cost,dp),solve1(n-2,cost,dp)) + cost[n]);
}
int MinCost2(int n,vector<int> cost){
    vector<int> dp(n,-1);
    dp[0] = cost[0];
    dp[1] = cost[1];
    if(n==0 || n==1){
        return 0;
    }
    // Min cost to reach nth step will be minimum of reaching (n-1)th and (n-2)th step; Note that here we do not add the cost of nth step, as we will not go somewhere then.
    return min(solve1(n-1,cost,dp),solve1(n-2,cost,dp)); 
}

// Dynamic Programming : Bottom-up Approach : Tabulation Method : 
// Time Complexity : O(n)
// Space Complexity : O(n)
// dp[i] denotes min cost to reach ith step + cost of that step. (The cost of that step is added because we will then always go to another step in the next iteration)
int MinCost(int n,vector<int> cost){
    vector<int> dp(n,-1);
    dp[0] = cost[0];
    dp[1] = cost[1];
    if(n==0 || n==1){
        return 0;
    }
    for(int i=2;i<n;i++){
        dp[i] = min(dp[i-1],dp[i-2])+cost[i];
    }
    return min(dp[n-1],dp[n-2]);
}

// Dynamic Programmming : Final Space Optimised Approah : 
int MinCostF(int n,vector<int> cost){
    int prev1 = cost[0];
    int prev2 = cost[1];
    if(n==0 || n==1){
        return 0;
    }
    for(int i=2;i<n;i++){
        int curr = min(prev1,prev2) + cost[i];
        prev1 = prev2;
        prev2 = curr;
    }
    return min(prev1,prev2);
}

int main(){
    cout<<"Enter the number of stairs"<<endl;
    int n;cin>>n;
    vector<int> cost(n,-1);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        cost[i] = x;
    }

    cout<<"Minimum cost to reach the top of stair is "<< MinCost(n,cost)<<endl;
    cout<<"Minimum cost to reach the top of stair is "<< MinCost1(n,cost)<<endl;
    cout<<"Minimum cost to reach the top of stair is "<< MinCost2(n,cost)<<endl;
    cout<<"Minimum cost to reach the top of stair is "<< MinCostF(n,cost)<<endl;
    return 0;
}