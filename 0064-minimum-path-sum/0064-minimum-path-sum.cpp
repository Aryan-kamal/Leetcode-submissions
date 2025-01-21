class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (m == 1 && n == 1)
            return grid[0][0];
        vector<vector<int>> dp(m, vector<int>(n, -1));
        fn(m - 1, n - 1, m, n, grid,dp);
        return dp[m-1][n-1];
    }
    int fn(int i, int j, int m, int n, vector<vector<int>>& grid,vector<vector<int>> &dp) {
        if (i == 0 && j == 0)
            return grid[0][0];
        if (i < 0 || j < 0)
            return INT_MAX;
        if(dp[i][j]!=-1)
            return dp[i][j];
        return dp[i][j]=grid[i][j] + min(fn(i - 1, j, m, n, grid,dp), fn(i, j - 1, m, n, grid,dp));
    }
};