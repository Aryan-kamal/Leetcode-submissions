class Solution {
public:
    // fn to find most frequent element and its frequency 
    pair<int, int> function(const vector<int>& arr) {
        unordered_map<int, int> freqMap;
        for (int num : arr)
            freqMap[num]++;
        int maxFreq = 0;
        int mostFrequentElement = arr[0];
        for (const auto& entry : freqMap) {
            if (entry.second > maxFreq) {
                maxFreq = entry.second;
                mostFrequentElement = entry.first;
            }
        }
        return {mostFrequentElement, maxFreq};
    }
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int x = function(nums).first; // dominant element 
        int f = function(nums).second; // its frequency 
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == x)
                cnt++;
            int remCnt = f - cnt;
            if (cnt * 2 > i + 1 && remCnt * 2 > n - i - 1)
                return i;
        }
        return -1;
    }
};