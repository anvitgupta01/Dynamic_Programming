#include <bits/stdc++.h>
using namespace std;

// With below problem , we come to know that i-d dp will be there when only one quantity among given is changed in the problem soluton.

// Recursion : 
int solve(int l,int x,int y,int z){
    if(l<0){
        return INT_MIN;
    }
    if(l==0){
        return 0;
    }

    int ans1 = solve(l-x,x,y,z) + 1;
    int ans2 = solve(l-y,x,y,z) + 1;
    int ans3 = solve(l-z,x,y,z) + 1;
    return max(max(ans1,ans2),ans3);
}
int Max_Seg_Rod(int l,int x,int y,int z){
    int ans = solve(l,x,y,z);
    if(ans<0){
        return 0;
    }
    return ans;
}


// Recursion + Memoization :
// dp[i] denotes the maximum number of segments made when length of rod is i. 
int solve1(int l,int x,int y,int z, vector<int>& dp){
    if(l<0){
        return INT_MIN;
    }
    if(dp[l]!=-1){
        return dp[l];
    }
    int ans1 = solve(l-x,x,y,z) + 1;
    int ans2 = solve(l-y,x,y,z) + 1;
    int ans3 = solve(l-z,x,y,z) + 1;
    dp[l] = max(max(ans1,ans2),ans3);
    return dp[l];
}
int Max_Seg_Rod1(int l,int x,int y,int z){
    vector<int> dp(l+1,-1);
    dp[0] = 0;
    int ans = solve1(l,x,y,z,dp);
    if(ans<0){
        return 0;
    }
    return ans;
}


// Tabulation method :
int Max_Seg_Rod2(int l,int x,int y,int z){
    vector<int> dp(l+1,INT_MIN);
    dp[0] = 0;
    
    for(int i=1;i<=l;i++){
        if(i-x >= 0){
            dp[i] = max(dp[i], dp[i-x] + 1);
        }
        if(i-y >= 0){
            dp[i] = max(dp[i], dp[i-y] + 1);
        }
        if(i-z >= 0){
            dp[i] = max(dp[i], dp[i-z] + 1);
        }
    }

    if(dp[l]<0){
        return 0;
    }
    return dp[l];
}
int Max_Seg_Rod3(int l,int x,int y,int z){
    vector<int> dp(l+1,-1);
    dp[0] = 0;
    
    for(int i=1;i<=l;i++){
        if(i-x >= 0 && dp[i-x]!=-1){
            dp[i] = max(dp[i], dp[i-x] + 1);
        }
        if(i-y >= 0 && dp[i-y]!=-1){
            dp[i] = max(dp[i], dp[i-y] + 1);
        }
        if(i-z >= 0 && dp[i-z]!=-1){
            dp[i] = max(dp[i], dp[i-z] + 1);
        }
    }

    if(dp[l]<0){
        return 0;
    }
    return dp[l];
}

// Space optimisations is not possible as :
// Tracking of i-x, i-y,i-z will be very difficult in it => it may be the case that time will then increase

int main(){
    int l,x,y,z;
    cin>>l>>x>>y>>z;

    cout<<"Maximum number of segments can be made will be "<<Max_Seg_Rod(l,x,y,z)<<endl;
    cout<<"Maximum number of segments can be made will be "<<Max_Seg_Rod1(l,x,y,z)<<endl;
    cout<<"Maximum number of segments can be made will be "<<Max_Seg_Rod2(l,x,y,z)<<endl;
    cout<<"Maximum number of segments can be made will be "<<Max_Seg_Rod3(l,x,y,z)<<endl;
}