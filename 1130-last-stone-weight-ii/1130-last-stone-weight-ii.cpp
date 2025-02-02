class Solution {
public:
    // Similar Question to LC2035 - Partition Array Into Two Arrays to Minimize Sum Difference (but for only +ve integers)
    int lastStoneWeightII(vector<int>& stones) {
        int totSum = 0;
        int n = stones.size();
        for (auto x : stones)
            totSum += x;

        // Subset Sum equal to target tabulation
        vector<vector<bool>> dp(n, vector<bool>(totSum + 1, 0));
        for (int i = 0; i < n; i++)
            dp[i][0] = true;
        if (stones[0] <= totSum)
            dp[0][stones[0]] = true;
        for (int ind = 1; ind < n; ind++) {
            for (int target = 1; target <= totSum; target++) {
                bool not_take = dp[ind - 1][target];
                bool take = false;
                if (stones[ind] <= target)
                    take = dp[ind - 1][target - stones[ind]];
                dp[ind][target] = take | not_take;
            }
        }

        int mini = 1e9;
        for (int i = 0; i <= totSum / 2; i++) {
            if (dp[n - 1][i])
                mini = min(mini, abs(i - (totSum - i)));
        }
        return mini;
    }
};