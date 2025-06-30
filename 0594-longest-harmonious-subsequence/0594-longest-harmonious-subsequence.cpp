class Solution {
public:
    int findLHS(vector<int>& nums) {
        // brute n^2
        // int n = nums.size();
        // sort(nums.begin(), nums.end());
        // int l = 0, r = n - 1, maxi = INT_MIN;
        // while (l < n) {
        //     if (abs(nums[r] - nums[l]) == 1) {
        //         maxi = max(maxi, r - l + 1);
        //         l++;
        //         r = n - 1;
        //     } else {
        //         if (l == r) {
        //             l++;
        //             r = n - 1;
        //         } else
        //             r--;
        //     }
        // }
        // return maxi == INT_MIN ? 0 : maxi;

        // M-2 optimal using hash map 
        unordered_map<int, int> freq;
        int res = 0;
        for (int num : nums)
            freq[num]++;
        for (auto& [key, val] : freq)
            if (freq.count(key + 1))
                res = max(res, val + freq[key + 1]);
        return res;  

        // M-3 
        // int n = nums.size();
        // sort(nums.begin(),nums.end());
        // int l=0,r=0,ans = 0;
        // while(j<n)
        // {
        //     if(nums[r]-nums[l] == 1) 
        //         ans = max(ans, r-l+1);
        //     while(nums[r]-nums[l] > 1) 
        //         l++;
        //     r++;
        // }
        // return ans;
    }
};