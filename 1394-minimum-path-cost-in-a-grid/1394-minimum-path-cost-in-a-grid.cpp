class Solution {
public:
    int function(int i, int j, int m, int n, vector<vector<int>>& grid,
                 vector<vector<int>>& moveCost,vector<vector<int>> &dp) {
        if(i==m-1)
            return grid[i][j];
        if (dp[i][j] != -1)
            return dp[i][j];
        int mini=1e9;
        for(int a=0;a<n;a++){
            mini = min(mini, function(i+1, a, m, n, grid, moveCost,dp)+grid[i][j]+moveCost[grid[i][j]][a]);
        }
        return dp[i][j]=mini;
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int mini = 1e9;
        for (int i = 0; i < n; i++) {
            mini = min(mini, function(0, i, m, n, grid, moveCost,dp));
        }
        return mini;
    }
};