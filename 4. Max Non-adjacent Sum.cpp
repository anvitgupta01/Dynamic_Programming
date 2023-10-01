#include <iostream>
#include <vector>
using namespace std;

// Recursion-left : 
// Any element can be included or excluded.
// In the below implementation, traversal starts from left.
int solve(vector<int> arr,int n, int i){
    if(i>=n){
        return 0;
    }
    int ans1 = arr[i] + solve(arr,n,i+2); // when arr[i] is included in the sum
    int ans2 = solve(arr,n,i+1); // when arr[i] is excluded in the sum
    return max(ans1,ans2);
}
int Max_Non_Sum(vector<int> arr){
    int n = arr.size();
    return solve(arr,n,0);
}

// Recursion-right
int solve3(vector<int> arr,int n){
    if(n<0){
        return 0;
    }
    if(n==0){
        return arr[0];
    }
    int ans1 = solve3(arr,n-2) + arr[n]; // when included
    int ans2 = solve3(arr,n-1); // when excluded
    return max(ans1,ans2);
}
int Max_Non_Sum3(vector<int> arr){
    int n = arr.size();
    return solve3(arr,n-1);
}


// Dynamic Programming : Recursion + Memoization : 
// Time complexity : O(n)
// Space Complexity : O(2*n)
int solve2(vector<int> arr,vector<int> dp,int n){
    if(n<0){
        return 0;
    }
    if(n==0){
        return arr[0];
    }
    int ans1 = solve3(arr,n-2) + arr[n]; // when included
    int ans2 = solve3(arr,n-1); // when excluded
    dp[n] = max(ans1,ans2);
    return dp[n];
}
int Max_Non_Sum2(vector<int> arr){
    int n = arr.size();
    vector<int> dp(n,-1);
    return solve2(arr,dp,n-1);
}


// Dynamic Programming : Tabulation : 
// dp[i] denotes max non adjacent sum for the array list of length = i.
// Time complexity : O(n)
// Space Complexity : O(n)
int Max_Non_Sum1(vector<int> arr){
    int n = arr.size();
    vector<int> dp(n,0);
    
    dp[0] = arr[0];
    dp[1] = max(arr[1],dp[0]);
    for(int i= 2;i<n;i++){
        int ans1 = dp[i-2] + arr[i];
        int ans2 = dp[i-1];
        dp[i] = max(ans1,ans2);
    }
    return dp[n-1];
}

// Dynamic Programming : Final Space Optimised Solution Code :
// Time complexity : O(n)
// Space Complexity : O(1)
int Max_Non_Sum4(vector<int> arr){
    int n = arr.size();
    int prev1 = arr[0];
    int prev2 = max(arr[0],arr[1]);
    for(int i = 2;i<n;i++){
        int ans = max(prev2,prev1 + arr[i]);
        prev1 = prev2;
        prev2 = ans;
    }
    return prev2;
}

int main(){
    cout<<"Enter number of elements in the list "<<endl;
    int n;cin>>n;
    vector<int> arr(n,-1);
    for(int i=0;i<n;i++){
        int x; cin>>x;
        arr[i] = x;
    }
    cout<<"Maximum non-adjacent sum will be "<< Max_Non_Sum(arr) << endl;
    cout<<"Maximum non-adjacent sum will be "<< Max_Non_Sum1(arr) << endl;
    cout<<"Maximum non-adjacent sum will be "<< Max_Non_Sum2(arr) << endl;
    cout<<"Maximum non-adjacent sum will be "<< Max_Non_Sum2(arr) << endl;
    cout<<"Maximum non-adjacent sum will be "<< Max_Non_Sum4(arr) << endl;
    return 0;
}