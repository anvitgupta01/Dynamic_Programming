#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define N 10e9+7

// Recursion approach : 
ll No_Of_Dearrange(int n){
    if(n==0 || n==1){
        return 0;
    }
    bool even = true;
    if(n%2 != 0){
        even = false;
    }
    if(even){
        return n*No_Of_Dearrange(n-1) + 1;
    }
    return n*No_Of_Dearrange(n-1) - 1;
}

// Alternate recursion : D(n) = (n-1)* (D(n-1) + D(n-2)) : Combining even and odd relations;
ll No_Of_Dearrange1(int n){
    if(n==0 || n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }
    return (n-1) * (No_Of_Dearrange(n-1) + No_Of_Dearrange(n-2));
}

// Dynamic Programming : Space Optimised Solution :
ll No_Of_Dearrange2(int n){
    if(n==0){
        return 0;
    }
    int prev1 = 0;
    int prev2 = 1;
    for(int i=3;i<=n;i++){
        int ans = (i-1) * (prev1 + prev2);
        prev1 = prev2;
        prev2 = ans;
    }
    return prev2;
} 


int main(){
    cout<<"Enter the number of elements "<<endl;
    int n;cin>>n;
    cout<<"Number of derarrangements are "<<No_Of_Dearrange(n)<<endl;
    cout<<"Number of derarrangements are "<<No_Of_Dearrange1(n)<<endl;
    cout<<"Number of derarrangements are "<<No_Of_Dearrange2(n)<<endl;
    return 0;
}