class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        int maxStreak = 0, currStreak = 0;
        for (int num : nums) {
            if (num == maxVal) {
                currStreak++;
                maxStreak = max(maxStreak, currStreak);
            } 
            else
                currStreak = 0;
        }
        return maxStreak;
    }
};