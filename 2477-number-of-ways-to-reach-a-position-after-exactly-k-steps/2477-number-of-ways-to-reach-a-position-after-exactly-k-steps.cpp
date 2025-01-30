class Solution {
public:
    const int mod = 1e9 + 7;
    int function(int i, int endPos, int k,vector<vector<int>> &dp) {
        if (k==0){
            if(i == endPos)
                return 1;
            else
                return 0;
        }    
        if (dp[i][k] != -1)
            return dp[i][k];
        int left = function(i - 1, endPos, k-1,dp)%mod;
        int right = function(i + 1, endPos, k-1,dp)%mod;
        return dp[i][k]=(left+right)%mod;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        int maxPos=2*k+startPos + 1;
        vector<vector<int>> dp(maxPos, vector<int>(k + 1, -1));
        return function(startPos+k, endPos+k, k,dp);
    }
};