class Solution {
public:
    int f(int ind, int prevInd, vector<int>& nums, vector<vector<int>>& dp) {
        if (ind == nums.size())
            return 0;
        if (dp[ind][prevInd + 1] != -1)
            return dp[ind][prevInd + 1];
        int take = 0;
        int nottake = f(ind + 1, prevInd, nums, dp); // not take
        if (prevInd == -1 || nums[ind] > nums[prevInd])
            take = 1 + f(ind + 1, ind, nums, dp); // take
        return dp[ind][prevInd + 1] = max(nottake, take);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return f(0, -1, nums, dp);
    }
};