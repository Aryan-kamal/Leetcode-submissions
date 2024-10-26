class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> ans;
        for (auto it : nums)
            mp[it]++;
        priority_queue<pair<int, int>> minHeap;
        for (auto it : mp) 
            minHeap.push(make_pair(it.second, -it.first));
        while (!minHeap.empty()) {
            int freq = minHeap.top().first;
            int num = -minHeap.top().second;
            minHeap.pop();
            for (int i = 0; i < freq; ++i)
                ans.push_back(num);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};