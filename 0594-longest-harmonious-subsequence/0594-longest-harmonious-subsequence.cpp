class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0, r = n - 1, maxi = INT_MIN;
        while (l < n) {
            if (abs(nums[r] - nums[l]) == 1) {
                maxi = max(maxi, r - l + 1);
                l++;
                r = n - 1;
            } else {
                if (l == r) {
                    l++;
                    r = n - 1;
                } else
                    r--;
            }
        }
        return maxi == INT_MIN ? 0 : maxi;
    }
};