class Solution {
public:
    int maxSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums.size() == 1)
            return nums[0];
        if (nums[nums.size() - 1] < 0)
            return nums[nums.size() - 1];
        int sum = 0;
        if (nums[0] > 0)
            sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1] && nums[i] > 0) {
                sum += nums[i];
            }
        }
        return sum;
    }
};