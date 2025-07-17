// vist prev ques for better understanding 

// M-1 DP - Using LIS Pattern (Bottom Up) (Last method of 3201)
// T.C : O(n^2); S.C : O(n*k)
// will pass with no problem 
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        
        //vector<int> dp1(n, 1); //mod1
        //vector<int> dp0(n, 1); //mod0
        // dp0 {} //mod0
        // dp1 {} //mod1
        //{
          //  {}, 0th row for mod0
           // {}  1st row for mod1         
        //}

        //row = 0 is for mod0
        //row = 1 is for mod1
        //row = 2 is for mod2
        //....
        //row = k-1 is for mod k-1
        vector<vector<int>> dp(k, vector<int>(n, 1));
        int maxSub = 1;
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                int mod = (nums[j] + nums[i]) % k;
                /*
                mod = 0 = 0th row , %2 = 0 waale case ka result
                mod = 1 = 1st row, %2 = 1 waale case ka result
                .
                .
                */
                dp[mod][i] = max(dp[mod][i], 1 + dp[mod][j]);
                maxSub = max(maxSub, dp[mod][i]);
            }
        }
        return maxSub;
    }
};


// M-2 DP - Using LIS Pattern (Rec+memo)
// T.C : Without Memoization O(2^n), With memoization - O(n^2) ; S.C : O(n^2)
// still MLE !
// class Solution {
// public:
//     int n, k;
//     vector<vector<vector<int>>> dp;
//     int LIS(vector<int>& nums, int i, int prev, int mod) {
//         if (i >= n) 
//             return 0;
//         if (dp[i][prev + 1][mod] != -1)
//             return dp[i][prev + 1][mod];
//         int take = 0, skip = 0;
//         if (prev == -1 || (nums[prev] + nums[i]) % k == mod)
//             take = 1 + LIS(nums, i + 1, i, mod);
//         skip = LIS(nums, i + 1, prev, mod);
//         return dp[i][prev + 1][mod] = max(take, skip);
//     }
//     int maximumLength(vector<int>& nums, int _k) {
//         n = nums.size();
//         k = _k;
//         dp.assign(n, vector<vector<int>>(n + 1, vector<int>(k, -1))); // dp[i][prev+1][mod] -> prev+1 because prev can be -1
//         int maxLen = 0;
//         for (int mod = 0; mod < k; ++mod)
//             maxLen = max(maxLen, LIS(nums, 0, -1, mod));
//         return maxLen;
//     }
// };