#include <bits/stdc++.h>
using namespace std;

int Ways(int n,int k){
    if(n==0){
        return 0;
    }
    int prev1 = k; // for n = 1;
    int prev2 = (k*k); // for n = 2;

    for(int i=3;i<=n;i++){
        int ans = (k-1) * (prev1 + prev2);
        prev1 = prev2;
        prev2 = ans;
    }
    return prev2;
}

int main(){
    cout<<"Enter the number of posts and colours available"<<endl;
    int n,k;
    cin>>n>>k;

    cout<<"Number of ways in which colour can be done "<<Ways(n,k)<<endl;
    return 0;
}