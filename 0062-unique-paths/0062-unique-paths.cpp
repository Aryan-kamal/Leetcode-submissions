class Solution {
public:
    int fn(int i,int j,int m,int n,vector<vector<int>> &dp){
        if(i==0 && j==0)
            return 1;
        if(i<0 || j<0)
            return 0;
        if(dp[i][j] !=-1)
            return dp[i][j];
        return dp[i][j] = fn(i-1,j,m,n,dp)+fn(i,j-1,m,n,dp);
    }
    int uniquePaths(int m, int n) {
        if(m==1 && n==1)
            return 1;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        fn(m-1,n-1,m,n,dp);
        return dp[m-1][n-1];
    }
};