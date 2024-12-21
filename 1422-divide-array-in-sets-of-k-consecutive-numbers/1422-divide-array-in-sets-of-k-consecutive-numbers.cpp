class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        // Greedy approach -
        int n=nums.size();
        if(n%k!=0)
            return false;
        map<int, int> mp;
        for (int num : nums) 
            mp[num]++;
        while(!mp.empty()){
            int start=mp.begin()->first;
            for (int i = 0; i < k; i++) {
                int current = start+i;
                if(mp[current]==0)
                    return false;
                mp[current]--;
                if(mp[current]==0)
                    mp.erase(current);
            }
        }
        return true;

        // Using heaps -
        // if (nums.size() % k != 0) 
        //     return false;
        // map<int, int> count;
        // for (int num : nums) 
        //     count[num]++;
        // priority_queue<int, vector<int>, greater<int>> minHeap;
        // for (auto& entry : count)
        //     minHeap.push(entry.first);
        // while (!minHeap.empty()) {
        //     int start = minHeap.top();
        //     if(count[start]==0)
        //     {
        //         minHeap.pop();
        //         continue;
        //     }
        //     for (int i = 0; i < k; i++) {
        //         int current = start + i;
        //         if (count[current] == 0)
        //             return false;
        //         count[current]--;
        //     }
        // }
        // return true;
    }
};