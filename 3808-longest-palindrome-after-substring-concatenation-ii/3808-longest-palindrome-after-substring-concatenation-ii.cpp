class Solution { 
public:
    // Function to compute the length of the longest palindrome that can be formed
    // by concatenating a substring from string s and a substring from string t.
    int longestPalindrome(string s, string t) {
        int n = s.size(), m = t.size();
        
        // 2D DP table for string s: ps[i][j] is true if s[i...j] is a palindrome.
        vector<vector<bool>> ps(n, vector<bool>(n, false));
        // maxs[i] stores the maximum length of a palindrome in s starting at index i.
        vector<int> maxs(n); 
        
        // maxt[j] stores the maximum length of a palindrome in t ending at index j.
        vector<int> maxt(m); 
        
        int ans = 0; // Variable to store the final answer (maximum palindrome length).
        
        // Fill the DP table for s (checking all substrings in s for palindrome property).
        // Loop backwards for the starting index i.
        for (int i = n - 1; i >= 0; i--) {
            // j runs from i to the end of the string.
            for (int j = i; j < n; j++) {
                // A substring s[i...j] is a palindrome if:
                // - It is a single character (j - i == 0),
                // - It is two characters and both are equal, or
                // - Its endpoints match (s[i] == s[j]) and the substring inside (s[i+1...j-1]) is a palindrome.
                ps[i][j] = (j - i == 0) || 
                           (j == i + 1 && s[i] == s[j]) || 
                           (ps[i + 1][j - 1] && (s[i] == s[j]));
                // If the current substring is a palindrome, update the maximum length starting at index i.
                if (ps[i][j]) {
                    maxs[i] = max(maxs[i], j - i + 1);
                    // Also update the global answer.
                    ans = max(ans, j - i + 1);
                }
            }
        }
        
        // 2D DP table for string t: pt[i][j] is true if t[i...j] is a palindrome.
        vector<vector<bool>> pt(m, vector<bool>(m, false));
        // Fill the DP table for t (checking all substrings in t for palindrome property).
        // Loop backwards for the starting index i.
        for (int i = m - 1; i >= 0; i--) {
            // j runs from i to the end of the string.
            for (int j = i; j < m; j++) {
                // A substring t[i...j] is a palindrome under similar conditions as s.
                pt[i][j] = (j - i == 0) || 
                           (j == i + 1 && t[i] == t[j]) || 
                           (pt[i + 1][j - 1] && (t[i] == t[j]));
                // If t[i...j] is a palindrome, update the maximum length ending at index j.
                if (pt[i][j]) {
                    maxt[j] = max(maxt[j], j - i + 1);
                    // Also update the global answer.
                    ans = max(ans, j - i + 1);
                }
            }
        }
        
        // 2D DP table for bridging palindromes between s and t.
        // dp[i][j] represents the additional length contributed by a matching pair s[i] and t[j].
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        // Iterate through s and t to build the combined palindrome from both strings.
        // Note: if s[i] == t[j], we consider the pair as contributing 2 to the palindrome length.
        for (int i = 0; i < n; i++) {
            // Iterate backwards in t.
            for (int j = m - 1; j >= 0; j--) {
                // If characters from s and t match, they can form the endpoints of a palindrome.
                if (s[i] == t[j]) {
                    // If we can extend from a previously computed dp value, do so.
                    // The value dp[i - 1][j + 1] holds the length from previous indices.
                    if (i > 0 && j < m - 1)
                        dp[i][j] = dp[i - 1][j + 1] + 2;
                    else
                        // Base condition: if we're at the boundary, the pair itself forms a palindrome of length 2.
                        dp[i][j] = 2;

                    // extra is used to include the best possible palindrome from either s (after i) or t (before j).
                    int extra = 0;
                    // Check the maximum palindrome length in s starting from the next index.
                    if (i + 1 < n)
                        extra = max(extra, maxs[i + 1]);
                    // Check the maximum palindrome length in t ending just before the current index.
                    if (j - 1 >= 0)
                        extra = max(extra, maxt[j - 1]);
                    // Update the global answer by considering the current pair (dp[i][j]) plus the best extension.
                    ans = max(ans, extra + dp[i][j]);
                }
            }
        }
        
        return ans; // Return the length of the longest palindrome found.
    }
};
