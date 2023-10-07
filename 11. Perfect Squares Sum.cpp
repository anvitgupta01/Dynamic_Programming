// Given an integer n, find and return the count of minimum numbers required to represent it as a sum of perfect squares.
// Example : for 41 = (5*5) + (6*6), hence answer is 2.

#include <bits/stdc++.h>
using namespace std;

// Recursion :
// It will time-out or will not give answer after n = 60;
int PS(int n){
    if(n==0 || n==1){
        return n;
    }

    int res = INT_MAX;
    int x = sqrt(n);
    for(int i=1;i<=x;i++){
        int ans = 1 + PS(n-(i*i));
        res = min(res,ans);
    }
    return res;
}

// Recursion + Memoization :
int solve1(int n,vector<int> &dp){
    if(dp[n] != -1){
        return dp[n];
    }
    int res = INT_MAX;
    int x = sqrt(n);
    for(int i=1;i<=x;i++){
        int ans = 1 + solve1(n-(i*i),dp);
        res = min(res,ans);
    }
    dp[n] = res;
    return dp[n];
}
int PS1(int n){
    vector<int> dp(n+1,-1);
    dp[0] = 0;
    dp[1] = 1;
    return solve1(n,dp);
}

// Tabulation : 
int PS2(int n){
    vector<int> dp(n+1,-1);
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2;i<=n;i++){
        int res = INT_MAX;
        int x = sqrt(i);
        for(int j=1;j<=x;j++){
            int ans = 1 + dp[i-j*j];
            res = min(res,ans);
        }
        dp[i] = res;
    }
    return dp[n];
}

int main(){
    cout<<"Enter the number please "<<endl;
    int n;cin>>n;

    cout<<"Your answer is "<<PS(n)<<endl;
    cout<<"Your answer is "<<PS1(n)<<endl;
    cout<<"Your answer is "<<PS2(n)<<endl;
    return 0;
}