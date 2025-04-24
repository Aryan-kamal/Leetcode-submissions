class Solution {
public:
    long long countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        // 1) How many distinct in the whole array?
        unordered_set<int> all(nums.begin(), nums.end());
        int k = all.size();
        
        // 2) Sliding window
        unordered_map<int,int> freq;
        long long ans = 0;
        int left = 0;
        
        for (int right = 0; right < n; ++right) {
            // include nums[right]
            freq[nums[right]]++;
            
            // 3) When we've covered all k distinct, count and shrink
            while ((int)freq.size() == k) {
                // Any end ≥ right still covers all k
                ans += (n - right);
                
                // shrink from left
                if (--freq[nums[left]] == 0)
                    freq.erase(nums[left]);
                left++;
            }
        }
        
        return ans;
    }
};
