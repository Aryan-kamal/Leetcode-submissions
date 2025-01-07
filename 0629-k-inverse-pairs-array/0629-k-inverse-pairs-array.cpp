class Solution {
public:
    // GPT code , try by own later
    const int MOD = 1e9 + 7;
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        dp[0][0] = 1; // Base case: There's 1 way to arrange 0 elements with 0 inversions
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                // Adding dp[i-1][j] and subtracting the value that exceeds
                // range of valid inversions
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
                if (j - i >= 0)
                    dp[i][j] = (dp[i][j] - dp[i - 1][j - i] + MOD) % MOD;
                if (j > 0)
                    dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
            }
        }
        return dp[n][k];
    }
};