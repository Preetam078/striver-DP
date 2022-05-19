#include<bits/stdc++.h>
using namespace std;

//this is the memorization approach - bottom-up
//TC-O(n)
//SC - O(n) + O(n)->recusion stack space
int func(vector<int>&dp, int n){
    if(n <= 1) return n;
    if(dp[n] != -1) return dp[n];

    return dp[n] = func(dp,n-1) + func(dp,n-2);
}

//Tabulation format Top down
//TC-O(n)
//SC-O(n) we saved the recursion stack space
int func2(vector<int>&dp, int n) {
    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

//TC-O(n)
//SC-O(1)
int func3(int n){

    int prev2 = 0;
    int prev = 1;

    for( int i = 2; i <= n; i++){
        int curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int main() {

    int n = 5;
    vector<int>dp(n+1,-1);
    vector<int>dp2(n+1,-1);
    cout<<"the fibonacci no. at n = 5 index is by memorization --> "<<func(dp,n)<<endl;
    cout<<"top-down answer --> "<<func2(dp,n)<<endl;
    cout<<"space optimization --> "<<func3(n);
    return 0;
}