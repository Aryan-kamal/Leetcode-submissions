class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0, r = 0, cnt = 1;
        while (r < nums.size()) {
            if (nums[r] - nums[l] > k) {
                l = r;
                cnt++;
            } 
            r++;
        }
        return cnt;
    }
};