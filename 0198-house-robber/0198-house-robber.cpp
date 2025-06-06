class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return function(n-1,nums,dp);
    }
    int function(int n,vector<int>& nums,vector<int>& dp){
        if(n==0)
            return nums[0];
        if(n<0)
            return 0;
        if(dp[n]!=-1)
            return dp[n];
        int pick=nums[n]+function(n-2,nums,dp);
        int nonPick=function(n-1,nums,dp);
        return dp[n]=max(pick,nonPick);
    }
};