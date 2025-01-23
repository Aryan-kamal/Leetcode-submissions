class Solution {
public:
    // Memoization (TLE) 
    // int minFallingPathSum(vector<vector<int>>& matrix) {
    //     int n = matrix.size();
    //     int m = matrix[0].size();
    //     vector<vector<int>> dp(n, vector<int>(m, -1));
    //     int mini = 1e9;
    //     for (int i = 0; i < m; i++)
    //         mini = min(mini, fn(0, i, n, m, matrix, dp));
    //     return mini;
    // }
    int fn(int i, int j, int n, int m, vector<vector<int>>& matrix,vector<vector<int>>& dp) {
        // This condition will be written before the base case to avoid overflow at j < 0 || j>=m and i==n-1 
        if (j < 0 || j>=m)
            return 1e9;
        if (i == n - 1) 
            return matrix[i][j];
        if (dp[i][j] != -1)
            return dp[i][j];
        int down = fn(i + 1, j, n, m, matrix, dp);
        int downLeft = fn(i + 1, j - 1, n, m, matrix, dp);
        int downRight = fn(i + 1, j + 1, n, m, matrix, dp);
        return dp[i][j] = matrix[i][j] + min({down, downLeft, downRight});
    }

    // Tabulation - 
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for(int i =0;i<m;i++)
            dp[0][i]=matrix[0][i];

        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int up=dp[i-1][j];
                int ld=1e9,rd=1e9;
                if(j-1>=0)
                    ld=dp[i-1][j-1];
                if(j+1<m)
                    rd=dp[i-1][j+1];
                dp[i][j]=matrix[i][j]+min({up,ld,rd});
            }
        }
        int mini = 1e9;
        for (int i = 0; i < m; i++)
            mini = min(mini, dp[n-1][i]);
        return mini;
    }
};