class Solution {
public:
    int function(int ind,int T,vector<int>& coins,vector<vector<int>> &dp){
        if(ind==0){
            if(T%coins[0]==0)
                return T/coins[0];
            else
                return 1e9;
        }
        if(dp[ind][T]!=-1)
            return dp[ind][T];
        int notTake=function(ind-1,T,coins,dp);
        int take=1e9;
        if(T>=coins[ind])
            take=1+function(ind,T-coins[ind],coins,dp);
        return dp[ind][T]=min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans=function(n-1,amount,coins,dp);
        if(ans==1e9)
            return -1;
        return ans;
    }
};