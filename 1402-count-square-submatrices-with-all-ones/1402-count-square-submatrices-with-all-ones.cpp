class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int sum = 0;
        vector<vector<int>> dp(n, vector<int>(m, 0));

        // Initialize first column
        for (int i = 0; i < n; i++) {
            dp[i][0] = matrix[i][0];
            sum += dp[i][0];
        }

        // Initialize first row, starting from j = 1 to avoid double counting
        // dp[0][0]
        for (int j = 1; j < m; j++) {
            dp[0][j] = matrix[0][j];
            sum += dp[0][j];
        }

        // Fill the rest of dp table
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == 0)
                    dp[i][j] = 0;
                else
                    dp[i][j] =
                        1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                sum += dp[i][j];
            }
        }
        return sum;
    }
};