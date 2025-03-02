class Solution {
public:
    bool solve(string &s, int l, int r,vector<vector<int>>&dp){
        if(l >= r) 
            return 1;
        if(dp[l][r] != -1)
            return dp[l][r];
        if(s[l] == s[r])
            return dp[l][r] = solve(s, l+1, r-1,dp);
        return dp[l][r] = 0;
    }
    string longestPalindrome(string s)
    {
    // M-1 is brute - gives TLE
    // int n=s.length();
    // string ans="";
    // for(int i=0;i<n;i++)
    // {
    //     string wd="";
    //     for(int j=i;j<n;j++)
    //     {
    //         wd+=s[j];
    //         string sd=wd;
    //         reverse(sd.begin(),sd.end());
    //         if(wd==sd && sd.length()>=ans.length())
    //             ans=sd;
    //     }
    // }
    // return ans;

    //   M-2 is this ie using 2 pointers
        int n=s.length();
        string ans="";
        ans+=s[0];
        // for odd palindrome 
        for(int i=0;i<n;i++)
        {
            int left=i,right=i;
            while(left>0 && right<n-1)
            {
                left--;right++;
                if(s[left]==s[right])
                {
                    int len=right-left+1;
                    if(len>ans.length())
                        ans=s.substr(left,len);
                }
                else
                    break;
            }
        }
        // for even palindrome -
        for(int i=0;i<n-1;i++)
        {
            int left=i,right=i+1;
            if(s[left]==s[right])
            {
                if(ans.length()<2)
                    ans=s.substr(left,2);
                while(left>0 && right<n-1)
                {
                    left--;right++;
                    if(s[left]==s[right])
                    {
                        int len=right-left+1;
                        if(len>ans.length())
                            ans=s.substr(left,len);
                    }
                    else
                        break;
                }
            }
        }
        return ans;
    
        // M-3 is DP (recursion + mem) -
        // int n = s.length();
        // int maxlen = INT_MIN;
        // int startingIndex = 0;
        // vector<vector<int>> dp(1001, vector<int>(1001, -1));
        // for(int i = 0; i < n; i++){
        //     for(int j = i; j < n; j++){
        //         if(solve(s, i, j,dp)) {
        //             if(j-i+1 > maxlen){
        //                 startingIndex = i;
        //                 maxlen = j-i+1;
        //             }
        //         }
                
        //     }
        // }
        // return s.substr(startingIndex, maxlen);

        // M-4 is DP (Tabulation ) - 

        // LCS approach with a slight modification - 
        // int n = s.size();
        // string rev = s;
        // reverse(rev.begin(), rev.end());
        // // dp[i][j] will hold the length of the longest common suffix of
        // // s[0...i-1] and rev[0...j-1]
        // vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        // int longest = 0;
        // int endIndex = 0;  // To store the ending index of the palindrome in s
        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= n; j++) {
        //         if (s[i - 1] == rev[j - 1]) {
        //             dp[i][j] = 1 + dp[i - 1][j - 1];
        //             // Calculate starting index of the current substring in s.
        //             int orig_start = i - dp[i][j];
        //             // In the reversed string, the substring ending at index j-1
        //             // corresponds to a substring starting at index (n - j) in s.
        //             int rev_start = n - j;
        //             // Only update if the alignment condition holds,
        //             // ensuring that the common substring is actually a palindrome.
        //             if (orig_start == rev_start && dp[i][j] > longest) {
        //                 longest = dp[i][j];
        //                 endIndex = i - 1;
        //             }
        //         } 
        //         else
        //             dp[i][j] = 0;
        //     }
        // }
        // return s.substr(endIndex - longest + 1, longest);

        // M-5 (Manacher's algorithm) (O(n)) (Not in syllabus)-
    }
};