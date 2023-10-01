// Question:
// You are given an array of n elements and an integer x representing the target sum. You have to tell the minimum number of elements you have to take to reach the target sum x.
// Note that : You have infinite number of elements of each type.

#include <iostream>
#include <vector>
using namespace std;

// Recursion :
int solve(vector<int> coins,int x){
    if(x==0){
        return 0;
    }
    if(x<0){
        return INT_MAX;
    }
    
    int mini = INT_MAX;
    for(int i=0;i<coins.size();i++){
        int answ = solve(coins,x-coins[i]);
        if(answ!=INT_MAX){
            mini = min(mini,answ+1); // +1 is done to add the coins[i] coin to the answ.
        }
    }

    return mini;
}
int MinNum(vector<int> coins,int x){
    int ans = solve(coins,x);
    if(ans==INT_MAX){
        return -1;
    }
    return ans;
}


// Recursion + Memoization : Top-down Approach : 
// Time complexity : O(x*n)
// Space Complexity : O(x+1+n)
// dp[i] denotes minimum number of coins required to make sum = i from the given coins in coin array.
int solve1(vector<int> coins,int x,vector<int> &dp){
    if(x<0){
        return INT_MAX;
    }
    if(dp[x]!=-1){
        return dp[x];
    }

    int mini = INT_MAX;
    for(int i=0;i<coins.size();i++){
        int answ = solve1(coins,x-coins[i],dp);
        if(answ!=INT_MAX){
            mini = min(mini,answ+1);
        }
    }
    dp[x] = mini;
    return dp[x];
}
int MinNum1(vector<int> coins,int x){
    vector<int> dp(x+1,-1);
    dp[0] = 0;
    int ans = solve1(coins,x,dp);
    if(ans==INT_MAX){
        return -1;
    }
    return ans;
}


// Tabulation Method : Bottom-up Approach :
// Time complexity : O(x*n)
// Space Complexity : O(x+1)
// dp[i] denotes minimum number of coins required to make sum = i from the given coins in coin array.
int MinNum2(vector<int> coins, int x){
    vector<int> dp(x+1,INT_MAX);
    dp[0] = 0;
    
    for(int i=1;i<dp.size();i++){
        for(int j=0;j<coins.size();j++){
            if((i-coins[j] >= 0) && (dp[i-coins[j]] != INT_MAX)){
                dp[i] = min(dp[i],dp[i-coins[j]]+1);
            }
        }
    }

    if(dp[x] == INT_MAX){
        return -1;
    }
    return dp[x];
}

// No furthur space optimisation possible : As dp[i] will depend on dp[i-coins[j]], which again will led to the same space complexity.

int main(){
    cout<<"Enter the length of the coins array"<<endl;
    int n;cin>>n;

    vector<int> coins(n,-1);
    for(int i=0;i<n;i++){
        int c;cin>>c;
        coins[i] = c;
    }

    cout<<"Enter the sum integer to be calculated"<<endl;
    int x;cin>>x;

    cout<<"Minimum number of coins required will be "<<MinNum(coins,x)<<endl;
    cout<<"Minimum number of coins required will be "<<MinNum1(coins,x)<<endl;
    cout<<"Minimum number of coins required will be "<<MinNum2(coins,x)<<endl;

    return 0;
}