class Solution {
public:
    int mod=1000000007;
    int fn(int i, int j, int m, int n, vector<vector<int>>& grid,
           vector<vector<vector<int>>>& dp, int k, int sum) {
        if (i == m - 1 && j == n - 1)
            // Check if the sum along the path equals k at the destination
            return ((sum + grid[i][j]) % k == 0) ? 1 : 0;

        if (i >= m || j >= n)
            return 0; // Out of bounds

        // Memoization check
        if (dp[i][j][sum] != -1)
            return dp[i][j][sum];

        // Recursively explore right and down paths
        int right = fn(i, j + 1, m, n, grid, dp, k, (sum + grid[i][j])%k)%mod;
        int down = fn(i + 1, j, m, n, grid, dp, k, (sum + grid[i][j])%k)%mod;

        // Store the result in dp array
        return dp[i][j][sum] = (right + down)%mod;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        // 3D dp array to store results (m x n x k)
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(k, -1)));
        return fn(0, 0, m, n, grid, dp, k, 0);
    }
};