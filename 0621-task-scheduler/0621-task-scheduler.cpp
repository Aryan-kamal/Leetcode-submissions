class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Greedy (O(n)) -
        vector<int>mp(26,0);
        for(auto ch:tasks)
            mp[ch-'A']++;
        sort(mp.begin(),mp.end());
        int maxFreq=mp[25];
        int gaddhe=maxFreq-1;
        int idleslots=n*gaddhe;
        for(int i=24;i>=0;i--)
            idleslots-=min(mp[i],gaddhe);
        return max(tasks.size(),tasks.size() + idleslots);

        // Using Heaps (O(n)) -
        // vector<int>mp(26,0);
        // priority_queue<int> maxHeap;
        // int time=0;

        // for(auto ch:tasks)
        //     mp[ch-'A']++;
        // for(auto f:mp){
        //     if(f!=0)
        //         maxHeap.push(f);
        // }

        // while(!maxHeap.empty()){
        //     vector<int>temp;
        //     for(int i=1;i<=n+1;i++){
        //         if(!maxHeap.empty()){
        //             int freq=maxHeap.top();
        //             maxHeap.pop();
        //             freq--;
        //             temp.push_back(freq);
        //         }
        //     }
        //     for(auto f:temp){
        //         if(f>0)
        //             maxHeap.push(f);
        //     }
        //     if(maxHeap.empty())
        //         return time+temp.size(); // this line will execute every time 
        //     time+=n+1;
        // }
        // return 0; // this line will never execute
    }
};