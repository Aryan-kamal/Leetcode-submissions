class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int mod = 1e9 + 7;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0, r = n - 1, cnt = 0;
        vector<int> power(n);
        power[0] = 1;
        for (int i = 1; i < n; i++)
            power[i] = (2 * power[i - 1]) % mod;
        while (l <= r) {
            int sum = nums[l] + nums[r];
            if (sum <= target) {
                cnt = (cnt % mod + power[r-l]) % mod;
                l++;
                // r=n-1; not required
            } else
                r--;
        }
        return cnt;
    }
};