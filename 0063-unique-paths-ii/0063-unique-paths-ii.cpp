class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        if(n==1 && m==1 && obstacleGrid[0][0] != 1)
            return 1;
        if (obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1)
            return 0;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        fn(n-1,m-1,n,m,dp,obstacleGrid);
        return dp[n-1][m-1];
    }
    int fn(int i,int j,int n,int m,vector<vector<int>> &dp,vector<vector<int>> &obstacleGrid){
        if(i>=0 && j>=0 && obstacleGrid[i][j]==1)
            return 0;
        if(i==0 && j==0)
            return 1;
        if(i<0 || j<0)
            return 0;
        if(dp[i][j] !=-1)
            return dp[i][j];
        return dp[i][j] = (fn(i-1,j,n,m,dp,obstacleGrid)+fn(i,j-1,n,m,dp,obstacleGrid));
    }
};