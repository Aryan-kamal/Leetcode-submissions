class Solution {
public:
    // int fib(int n) {
    //     if(n<=1)
    //         return n;
    //     return fib(n-1)+fib(n-2);
    // }
    
    int fn(int n,vector<int>&dp) {
        if(n<=1)
            return n;
        if(dp[n]!=-1)
            return dp[n];
        return dp[n]=fn(n-1,dp)+fn(n-2,dp);
    }
    int fib(int n){
        vector<int>dp(n+1,-1);
        return fn(n,dp);
    }
};