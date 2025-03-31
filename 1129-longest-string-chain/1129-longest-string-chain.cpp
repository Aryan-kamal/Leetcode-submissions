class Solution {
public:
    bool checkpossible(string &s1, string &s2) {
        int n = s1.size();
        int m = s2.size();
        if (n != m + 1)
            return false;
        int first = 0, second = 0;
        while (first < n) {
            if (s1[first] == s2[second] && second < m) {
                first++;
                second++;
            } else
                first++;
        }
        if (first == n && second == m)
            return true;
        return false;
    }
    static bool compr(string &s1,string &s2){
        return s1.size()<s2.size();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n, 1);
        int maxInd = 0;
        sort(words.begin(),words.end(),compr);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (checkpossible(words[i], words[j]) && dp[j] + 1 > dp[i])
                    dp[i] = dp[j] + 1;
            }
            if (dp[i] > dp[maxInd]) // or maxi = max(maxi,dp[i])  then return maxi
                maxInd = i;
        }
        return dp[maxInd];
    }
};