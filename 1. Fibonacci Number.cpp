#include <iostream>
#include <vector>
using namespace std;

// Pure Recursion:
int FiboNum(int n){
    if(n==0 || n==1){
        return n;
    }
    return FiboNum(n-1)+FiboNum(n-2);
}

// Dynamic Programming : Recursion and Memoization : Top-down Approach : 
// Time complexity : O(n)
// Space complexity : O(2*n) = By recursive stack as well as the dp array/vector.
int FiboNum2(int n, vector<int> &v){
    v[0] = 0;
    v[1] = 1;
    if(v[n]!=-1){
        return v[n];
    }
    return v[n] = FiboNum2(n-1,v) + FiboNum2(n-2,v);
}

// Dynamic Programming : Tabulation : Bottom-up Approach :  
// Time complexity : O(n)
// Space complexity : O(n) = By the dp array/vector.
int FiboNum1(int n){
    vector<int> v(n+1,-1);
    v[0] = 0;
    v[1] = 1;
    for(int i=2;i<(n+1);i++){
        v[i] = v[i-1] + v[i-2];
    }
    return v[n];
}


// Space Optimisations : An element depend only on previous two :
// Time complexity : O(n)
// Space Complexity : O(1)
int FiboNum3(int n){
    int prev1 = 0;
    int prev2 = 1;
    if(n==0){
        return 0;
    }
    for(int i=2;i<=n;i++){
        int curr = prev1+prev2;
        prev1 = prev2;
        prev2 = curr;
    }
    return prev2;
}

int main(){
    cout<<"Enter the index of the number you want"<<endl;
    int n;
    cin>>n;
    vector<int> v(n+1,-1); // Required in recursion + memoization
    cout<<"Corresponding number in fibonacci series is "<<FiboNum(n)<<endl;
    cout<<"Corresponding number in fibonacci series is "<<FiboNum1(n)<<endl;
    cout<<"Corresponding number in fibonacci series is "<<FiboNum3(n)<<endl;
    cout<<"Corresponding number in fibonacci series is "<<FiboNum2(n,v)<<endl;
    return 0;
}
