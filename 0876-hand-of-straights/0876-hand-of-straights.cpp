class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize!=0)
            return false;
        map<int, int> mp;
        for (int num : hand) 
            mp[num]++;
        while(!mp.empty()){
            int start=mp.begin()->first;
            for (int i = 0; i < groupSize; i++) {
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
        // if (hand.size() % groupSize != 0) 
        //     return false;
        // map<int, int> count;
        // for (int num : hand) 
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
        //     for (int i = 0; i < groupSize; i++) {
        //         int current = start + i;
        //         if (count[current] == 0)
        //             return false;
        //         count[current]--;
        //     }
        // }
        // return true;
    }
};