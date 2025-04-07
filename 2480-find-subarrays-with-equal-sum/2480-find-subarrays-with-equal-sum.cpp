class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mp; // Using std::map for a sorted map.
        for (int i = 0; i < n - 1; i++) {
            int sum = nums[i] + nums[i + 1];
            mp[sum]++;
            // Early return if any sum appears twice
            if (mp[sum] == 2)
                return true;
        }
        return false;
    }
};