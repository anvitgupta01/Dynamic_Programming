#include <iostream>
#include <vector>
using namespace std;

//Only Recursion : Method1 : 
// In this, we take add number of ways for reaching (n-1)th step and (n-2)th step : 
int NumWay(int n){
    if(n==0 || n==1){
        return 1;
    }
    return NumWay(n-1)+NumWay(n-2);
}

// Only Recursion : Method2 :
// In this, we will add number of ways to reach nth step from 1st and 2nd step : 
int solve1(int n,int i){
    if(i==n){
        return 1;
    }
    if(i>n){
        return 0;
    }
    return (solve1(n,i+1) + solve1(n,i+2));
}
int NumWay1(int n){
    return solve1(n,0);
}

// Dynamic Programming : Bottom-up Approach : Tabulation Method : 
// dp[i] denotes number of ways to reach nth step from ith step : 
// Time Complexity : O(n)
// Space Complexity : O(n) = Due to dp vector/array
int solve2(int n ,vector<int> &dp){
    for(int i =(n-2);i>=0;i--){
        dp[i] = dp[i+1]+dp[i+2];
    }
    return dp[0];
}
int NumWay2(int n){
    vector<int> dp(n+1,-1);
    dp[n] = 1;
    dp[n-1] = 1;
    return solve2(n,dp);
}

// Dynamic Programming : Top-down Approach : Recursion + Memoization : 
// Time Complexity : O(n)
// Space Complexity : O(2*n) = Due to dp array/vector and recursive stack
int solve3(int n,int i,vector<int> &dp){
    if(i==n || i==(n-1)){
        return 1;
    }
    return dp[i] = solve3(n,i+1,dp)+solve3(n,i+2,dp);
}
int NumWay3(int n){
    vector<int> dp(n+1,-1);
    dp[n] = 1;
    dp[n-1] = 1;
    return solve3(n,0,dp); // Number of ways to reach nth step from 0th step.
}

// Dynamic Programming : Final Space optimised Solution :
int NumWayF(int n){
    int prev1 = 1;
    int prev2 = 1;
    for(int i=(n-2);i>=0;i--){
        int curr = prev1+prev2;
        prev1 = prev2;
        prev2 = curr;
    }
    return prev2;
}


int main(){
    cout<<"Enter the number of stairs"<<endl;
    int n;cin>>n;

    cout<<"Number of ways to reach the top are "<<NumWay(n)<<endl;
    cout<<"Number of ways to reach the top are "<<NumWay1(n)<<endl;
    cout<<"Number of ways to reach the top are "<<NumWay2(n)<<endl;
    cout<<"Number of ways to reach the top are "<<NumWay2(n)<<endl;
    cout<<"Number of ways to reach the top are "<<NumWayF(n)<<endl;
    return 0;
}