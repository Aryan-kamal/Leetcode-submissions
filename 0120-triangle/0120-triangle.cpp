class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return fn(0, 0, n, triangle,dp);
        return dp[0][0];
    }
    int fn(int i, int j, int n, vector<vector<int>>& triangle,vector<vector<int>> &dp) {
        if (i == n - 1)
            return triangle[i][j];
        if (j > i+1)
            return INT_MAX;
        if (dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j]=triangle[i][j] +
               min(fn(i + 1, j, n, triangle,dp), fn(i + 1, j + 1, n, triangle,dp));
    }
};