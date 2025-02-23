class Solution {
public:
    // int function(string text1, string text2,int i,int j,vector<vector<int>> &dp){
    //     if(i<0||j<0)
    //         return 0;
    //     if(dp[i][j]!=-1)
    //         return dp[i][j];
    //     int a=-1e9;
    //     if(text1[i]==text2[j])
    //         return dp[i][j]=1+function(text1,text2,i-1,j-1,dp);
    //     return dp[i][j]=max(function(text1,text2,i-1,j,dp),function(text1,text2,i,j-1,dp));
    // }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length();
        int m=text2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        // Base cases but already covered in initialising dp array 
        // for(int j=0;j<=m;j++)
        //     dp[0][j]=0;
        // for(int i=0;i<=n;i++)
        //     dp[i][0]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};