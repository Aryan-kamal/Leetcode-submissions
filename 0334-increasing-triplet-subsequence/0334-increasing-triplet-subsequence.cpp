class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // M-1 (DP gives TLE)
        // int n=nums.size();
        // vector<int> dp(n,1);
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<i;j++){
        //         if(nums[i]>nums[j] && dp[j]+1 > dp[i]){
        //             dp[i]=dp[j]+1;
        //             if(dp[i]>=3)
        //                 return true;
        //         }
        //     }
        // }
        // return false;

        // M-2 (Greedy)-
        int first = INT_MAX, second = INT_MAX;
        for (int num : nums) {
            if (num <= first)
                first = num; // Smallest number so far
            else if (num <= second)
                second = num; // Second smallest number
            else
                return true; // Found third element larger than both
        }
        return false;
    }
};