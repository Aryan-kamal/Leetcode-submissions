class Solution {
public:
    bool canPartition(vector<int>& arr) {
        int n = arr.size();
        int target=0;
        for(int i=0;i<n;i++)
            target+=arr[i];
        if(target%2!=0)
            return false;
        vector<vector<int>> dp(n, vector<int>(target/2+1, -1));
        return function(0, target/2, n, arr, dp);
    }

    bool function(int ind, int target, int n, vector<int>& arr,vector<vector<int>>& dp) {
        if (target == 0)
            return true;
        if (ind == n - 1)
            return (arr[n - 1] == target);
        if (dp[ind][target] != -1)
            return dp[ind][target];
        bool notTake = function(ind + 1, target, n, arr, dp);
        bool take = false;
        if (arr[ind] <= target)
            take = function(ind + 1, target - arr[ind], n, arr, dp);
        return dp[ind][target] = take | notTake;
    }
};