class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size();

        // M-1 (LIS approach,TLE) -
        // vector<int> dp(n,1);
        // int maxi=0;
        // for(int i=1;i<=26;i++){
        //     for(int j=0;j<i;j++){
        //         if(abs(i-s[j])<=k && dp[j]+1 > dp[i]){
        //             dp[i]=dp[j]+1;
        //         }
        //     }
        //     maxi = max(maxi,dp[i]);
        // }
        // return maxi;

        // M-2 (n^2, Optimal) -
        vector<int> dp(26, 0);
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            int ind=s[i] - 'a';
            int left = max(0, ind - k);
            int right = min(25, ind + k);
            int longest = 0;
            for (int j = left; j <= right; j++) {
                longest = max(dp[j], longest);
            }
            dp[ind] = longest + 1;
            maxi = max(maxi, dp[ind]);
        }
        return maxi;
    }
};