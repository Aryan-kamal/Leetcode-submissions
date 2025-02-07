class Solution {
public:
    int function(vector<int>& nums, int target,int temp, int ind,vector<vector<int>> &dp) {
        if (temp == target)
            return 0;
        if (ind == nums.size()||temp>target)
            return -1e9;
        if (dp[ind][temp] != -1) {
            return dp[ind][temp];
        }
        int take=1+function(nums, target,temp+nums[ind], ind + 1,dp);
        int not_take=0+function(nums, target, temp, ind + 1,dp);
        return dp[ind][temp]=max(take,not_take);
    }

    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int temp=0;
        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));
        int ans= function(nums, target, temp, 0,dp);
        if(ans<=-1e8)
            return -1;
        return ans;
    }
};