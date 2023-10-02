#include <bits/stdc++.h>
using namespace std;

// Using Recursion : 
int solve(vector<int> weight, vector<int> value,int n,int maxW){
    if(n==0){
        if(weight[n] > maxW){
            return 0;
        }
        else{
            return value[n];
        }
    }
    if(maxW <= 0){
        return 0;
    }
    int ans1 = solve(weight,value,n-1,maxW-weight[n]) + value[n];
    int ans2 = solve(weight,value,n-1,maxW);
    return max(ans1,ans2);
}
int Knapsack(vector<int> weight,vector<int> value,int n,int maxW){
    return solve(weight,value,n-1,maxW);
}


// Dynamic Programming : Recursion + Memoization :
int solve1(vector<int> weight,vector<int> value,int n,int maxW,vector<vector<int>> dp){
    if(n==0){
        if(weight[n] > maxW){
            return 0;
        }
        else{
            return value[n];
        }
    }

    if(dp[maxW][n] != -1){
        return dp[maxW][n];
    }

    int ans1 = solve1(weight,value,n-1,maxW-weight[n],dp) + value[n];
    int ans2 = solve1(weight,value,n-1,maxW,dp);

    dp[maxW][n] = max(ans1,ans2);
    return dp[maxW][n];
}
int Knapsack1(vector<int> weight,vector<int> value,int n,int maxW){
    vector<vector<int>> dp(maxW+1,vector<int>(n,-1));
    for(int i=0;i<(n);i++){
        dp[0][i] = 0;
    }
    return solve1(weight,value,n-1,maxW,dp);
}


// Dynamic Programming : Tabulation : 
int Knapsack2(vector<int> weight, vector<int> value,int n,int maxW){
    // Initialise the dp array :
    vector<vector<int>> dp(maxW+1,vector<int>(n,-1));

    // Analyse the base case : 
    for(int i=0;i<n;i++){
        dp[0][i] = 0;
    }
    for(int i=0;i<=maxW;i++){
        if(weight[0] <= i){
            dp[i][0] = value[0];
        }
        else{
            dp[i][0] = 0;
        }
    }

    // Iteration : 
    for(int i=1;i<=maxW;i++){
        for(int j=1;j<n;j++){
            int include = 0;
            if(weight[j] <= i){
                include = value[j] + dp[i-weight[j]][j-1];
            }
            int exclude = dp[i][j-1];
            dp[i][j] = max(exclude,include);
        }
    }
    return dp[maxW][n-1];
} 

int Knapsack3(vector<int> weight, vector<int> value,int n,int maxW){
    // Initialise the dp array :
    vector<int> prev(maxW+1,-1);
    vector<int> curr(maxW+1,-1);

    // Analyse the base case : 
    for(int i=0;i<=maxW;i++){
        if(weight[0] <= i){
            prev[i] = value[0];
        }
        else{
            prev[i] = 0;
        }
    }

    // Iteration : 
    for(int j=1;j<n;j++){
        for(int i=1;i<=maxW;i++){
            int include = 0;
            if(weight[j] <= i){
                include = value[j] + prev[i-weight[j]];
            }
            int exclude = prev[i];
            curr[i]= max(exclude,include);
        }
        prev = curr;
    }
    return prev[maxW];
} 


int Knapsack4(vector<int> weight, vector<int> value,int n,int maxW){
    // Initialise the dp array :
    vector<int> curr(maxW+1,-1);

    // Analyse the base case : 
    for(int i=0;i<=maxW;i++){
        if(weight[0] <= i){
            curr[i] = value[0];
        }
        else{
            curr[i] = 0;
        }
    }

    // Iteration : 
    for(int j=1;j<n;j++){
        for(int i= maxW;i>=0;i--){
            int include = 0;
            if(weight[j] <= i){
                include = value[j] + curr[i-weight[j]];
            }
            int exclude = curr[i];
            curr[i]= max(exclude,include);
        }
    }
    return curr[maxW];
} 



int main(){
    cout<<"Enter the number of items"<<endl;
    int n;cin>>n;

    vector<int> weight(n,-1);
    vector<int> value(n,-1);

    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        weight[i] = x;
        value[i] = y;
    }

    cout<<"Enter the maximum weight that the knapsack can carry"<<endl;
    int maxW;cin>>maxW;

    cout<<"The maximum value that a theif can stole will be "<<Knapsack(weight,value,n,maxW)<<endl;
    cout<<"The maximum value that a theif can stole will be "<<Knapsack1(weight,value,n,maxW)<<endl;
    cout<<"The maximum value that a theif can stole will be "<<Knapsack2(weight,value,n,maxW)<<endl;
    cout<<"The maximum value that a theif can stole will be "<<Knapsack3(weight,value,n,maxW)<<endl;
    cout<<"The maximum value that a theif can stole will be "<<Knapsack4(weight,value,n,maxW)<<endl;
    return 0;
}