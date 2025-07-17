// M-1 max({even no's subsequence, odd no's subsequence, alternating parity subsequence})
// No TLE and MLE; TC = n  ; SC = 1
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int countEven = 0, countOdd = 0;
        for (int num : nums) {
            if (num % 2 == 0) 
                countEven++;
            else 
                countOdd++;
        }
        int altLen = 1; // At least one number
        int prevParity = nums[0] % 2;
        for (int i = 1; i < nums.size(); ++i) {
            int currParity = nums[i] % 2;
            if (currParity != prevParity) {
                altLen++;
                prevParity = currParity;
            }
        }
        return max({countEven, countOdd, altLen});
    }
};

// M-2 DP - Using LIS Pattern (Recursion) - Memoization will give MLE due to high constraints
// T.C : Without Memoization O(2^n), With memoization - O(n^2) but MLE; S.C : O(n^2)
// class Solution {
// public:
//     int LIS(vector<int>& nums, int i, int prev, int mod) {
//         if(i >= nums.size())
//             return 0;
//         int take = 0,skip = 0;
//         if(prev == -1 || (nums[prev] + nums[i])%2 == mod)
//             take = 1 + LIS(nums, i+1, i, mod);
//         skip = LIS(nums, i+1, prev, mod);
//         return max(take, skip);
//     }
//     int maximumLength(vector<int>& nums) {
//         int maxSubLength = 0;
//         maxSubLength = max(maxSubLength, LIS(nums, 0, -1, 0)); //%2 == 0 k lie
//         maxSubLength = max(maxSubLength, LIS(nums, 0, -1, 1)); //%2 == 1 k lie
//         return maxSubLength;
//     }
// };


// M-3 - Using LIS Pattern (Bottom Up) - TLE
//T.C : O(n^2) but TLE; S.C : O(n)
// class Solution {
// public:
//     int maximumLength(vector<int>& nums) {
//         int n = nums.size();
        
//         //vector<int> dp1(n, 1); //mod1
//         //vector<int> dp0(n, 1); //mod0
//         // dp0 {} //mod0
//         // dp1 {} //mod1
//         //{
//           //  {}, 0th row for mod0
//            // {}  1st row for mod1         
//         //}

//         //row = 0 is for mod0
//         //row = 1 is for mod1
//         vector<vector<int>> dp(2, vector<int>(n, 1));
//         int maxSub = 1;
//         for(int i = 1; i < n; i++) {
//             for(int j = 0; j < i; j++) {
//                 int mod = (nums[j] + nums[i])%2;
//                 //mod = 0 = 0th row , %2 = 0 waale case ka result
//                 //mod = 1 = 1st row, %2 = 1 waale case ka result
//                 dp[mod][i] = max(dp[mod][i], 1 + dp[mod][j]);
//                 maxSub = max(maxSub, dp[mod][i]);
//             }
//         }
//         return maxSub;
//     }
// };