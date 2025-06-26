//M-1 (Using Recursion) O(2^n), take and skip
// class Solution {
// public:
//     int solve(const string &s, int k, int i,int n) {
//         if (i < 0) 
//             return 0;
//         int take = 0;
//         int bit  = s[i] - '0';
//         long long value = (bit == 1 ? (1LL << (n - i - 1)) : 0);

//         if (value <= k)
//             take = 1 + solve(s, k - value, i - 1,n);
//         int skip = solve(s, k, i - 1,n);
//         return max(take, skip);
//     }
//     int longestSubsequence(string &s, int k) {
//         int n = s.length();
//         return solve(s, k, n-1,n);
//     }
// };

// M-2 Memoization - 
// class Solution {
// public:
//     unordered_map<int, unordered_map<long long, int>> dp;
//     int solve(const string &s, int k, int i, int n) {
//         if (i < 0) 
//             return 0;

//         if (dp[i].count(k)) 
//             return dp[i][k];

//         int take = 0;
//         int bit = s[i] - '0';
//         long long value = (bit == 1 ? (1LL << (n - i - 1)) : 0);

//         if (value <= k)
//             take = 1 + solve(s, k - value, i - 1, n);
//         int skip = solve(s, k, i - 1, n);
//         return dp[i][k] = max(take, skip);
//     }

//     int longestSubsequence(string &s, int k) {
//         int n = s.length();
//         dp.clear(); // optional if using same object multiple times
//         return solve(s, k, n - 1, n);
//     }
// };

// M-3 (Greedy) (O(n))-
class Solution {
public:
    int longestSubsequence(string s, int k) {
        int length = 0;
        long long powerValue = 1;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == '0')
                length++;
            else if(powerValue <= k) {
                length++;
                k -= powerValue;
            }
            if (powerValue <= k)
                powerValue <<= 1; //powerValue *= 2;
        }
        return length;
    }
};

