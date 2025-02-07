class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans=function(n-1,amount,coins,dp);
        return ans;
    }
    int function(int ind,int T,vector<int>& coins,vector<vector<int>> &dp){
        if(ind<0){
            if(T==0)
                return 1;
            else
                return 0;
        }
        if(dp[ind][T]!=-1)
            return dp[ind][T];
        int notTake=function(ind-1,T,coins,dp);
        int take=0;
        if(T>=coins[ind])
            take=function(ind,T-coins[ind],coins,dp);
        return dp[ind][T]=take+notTake;
    }
};