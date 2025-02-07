class Solution {
public:
    // int function(vector<int>& nums, int target, int sum, int ind) {
    //     if (ind == nums.size()) {
    //         if (sum == target)
    //             return 1;
    //         else
    //             return 0;
    //     }
    //     int sub = function(nums, target, -1 * nums[ind] + sum, ind + 1);
    //     int plus = function(nums, target, nums[ind] + sum, ind + 1);
    //     return plus + sub;
    // }
    // int findTargetSumWays(vector<int>& nums, int target) {
    //     return function(nums, target, 0, 0);
    // }

    int function(vector<int>& nums, int target, int sum, int ind,vector<vector<int>>& dp) {
        if (ind == nums.size()) {
            if (sum == target)
                return 1;
            else
                return 0;
        }
        // Since the `sum` can be negative, shift the range to ensure positive indexing
        if (dp[ind][sum + 1000] !=-1) // Assuming the sum is between -1000 to 1000
            return dp[ind][sum + 1000];
        int sub = function(nums, target, sum - nums[ind], ind + 1, dp);
        int plus = function(nums, target, sum + nums[ind], ind + 1, dp);
        return dp[ind][sum + 1000] = plus + sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 1000; // Based on the constraints, sum is within [-1000, 1000]
        vector<vector<int>> dp(nums.size(), vector<int>(2 * totalSum + 1, -1));
        return function(nums, target, 0, 0, dp);
    }
};