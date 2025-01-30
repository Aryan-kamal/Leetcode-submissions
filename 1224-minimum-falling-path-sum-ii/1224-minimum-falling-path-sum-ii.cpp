class Solution {
public:
    // Memoiztion -
    // int minFallingPathSum(vector<vector<int>>& matrix) {
    //     int n = matrix.size();
    //     vector<vector<int>> dp(n, vector<int>(n, -1));
    //     int mini = 1e9;
    //     for (int i = 0; i < n; i++)
    //         mini = min(mini, fn(0, i, n, matrix, dp));
    //     return mini;
    // }
    // int fn(int i, int j, int n, vector<vector<int>>& matrix,
    //        vector<vector<int>>& dp) {
    //     // This condition will be written before the base case to avoid overflow
    //     // at j < 0 || j>=m and i==n-1
    //     if (j < 0 || j >= n)
    //         return 1e9;
    //     if (i == n - 1)
    //         return matrix[i][j];
    //     if (dp[i][j] != -1)
    //         return dp[i][j];
    //     int mini=1e9;
    //     for(int k=0;k<n;k++){
    //         if(k!=j)
    //             mini=min(mini,fn(i + 1,k, n, matrix, dp));
    //     }
    //     return dp[i][j] = matrix[i][j]+mini;
    // }

    // Tabulation -
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for(int i =0;i<n;i++)
            dp[0][i]=matrix[0][i];

        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int mini=1e9;
                for(int k=0;k<n;k++){
                    if(k!=j)
                        mini=min(mini,dp[i-1][k]);
                }
                dp[i][j] = matrix[i][j]+mini;
            }
        }
        int mini = 1e9;
        for (int i = 0; i < n; i++)
            mini = min(mini, dp[n-1][i]);
        return mini;
    }
};