class Solution {
public:
    // M-1 (rec + mem)
    // bool solve(string &s, int l, int r,vector<vector<int>>&dp){
    //     if(l >= r) 
    //         return 1;
    //     if(dp[l][r] != -1)
    //         return dp[l][r];
    //     if(s[l] == s[r])
    //         return dp[l][r] = solve(s, l+1, r-1,dp);
    //     return dp[l][r] = 0;
    // }
    // int countSubstrings(string s) {
    //     int n = s.length();
    //     int cnt=0;
    //     vector<vector<int>> dp(1001, vector<int>(1001, -1));
    //     for(int i = 0; i < n; i++){
    //         for(int j = i; j < n; j++){
    //             if(solve(s, i, j,dp))
    //                 cnt++;        
    //         }
    //     }
    //     return cnt;
    // }

    // M-2 (tabulation) -
    
    // M-3 (2 pointer apporach) (most optimal) -
    int countSubstrings(string s) {
        int n = s.length();
        int cnt=0;
        for(int i=0;i<n;i++){

            // Odd palindromes - 
            int a=i,b=i;
            while(a>=0 && b<n && s[a]==s[b]){
                cnt++;
                a--;
                b++;
            }

            // Even palindromes 
            a=i;
            b=i+1;
            while(a>=0 && b<n && s[a]==s[b]){
                cnt++;
                a--;
                b++;
            }
        }
        return cnt;
    }
};