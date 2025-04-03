class Solution {
public:
    int function(int i, int j, string& s1, string& s2,
                 vector<vector<int>>& dp) {
        if (i >= s1.size() && j >= s2.size())
            return 0;
        if (i >= s1.size())
            return s2[j] + function(i, j + 1, s1, s2, dp);
        if (j >= s2.size())
            return s1[i] + function(i + 1, j, s1, s2, dp);

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s1[i] == s2[j])
            return dp[i][j] = function(i + 1, j + 1, s1, s2, dp);
        int a = s1[i] + function(i + 1, j, s1, s2, dp);
        int b = s2[j] + function(i, j + 1, s1, s2, dp);
        return dp[i][j] = min(a, b);
    }
    int minimumDeleteSum(string s1, string s2) {
        // M-1 Rec + Memo (Edit distance approach or standard DP approach) -
        // vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), -1));
        // return function(0,0,s1,s2,dp);

        // M-2 LCS approach -
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = s1[i - 1] + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        int sum = 0;
        for (auto c : s1)
            sum += c;
        for (auto c : s2)
            sum += c;
        return sum - 2 * dp[n][m]; // minimumDeleteSum=asciiSum(s1)+asciiSum(s2)−2∗asciiSum(LCS)
    }
};