class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) 
            return nums[0];
        vector<int> dp1(n, -1); // for excluding the first house
        vector<int> dp2(n, -1); // for excluding the last house
        vector<int> numsWithoutFirst(nums.begin() + 1, nums.end());  // nums[1:n]
        vector<int> numsWithoutLast(nums.begin(), nums.end() - 1);   // nums[0:n-1]
        return max(function(n - 2, numsWithoutFirst, dp1), function(n - 2, numsWithoutLast, dp2));
    }
    int function(int n, vector<int>& arr, vector<int>& dp) {
        if (n == 0)
            return arr[0];
        if (n < 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];
        int pick = arr[n] + function(n - 2, arr, dp);
        int nonPick = function(n - 1, arr, dp);
        return dp[n] = max(pick, nonPick);
    }
};