class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        if(n==0)
            return {};
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        int rank=0;
        for(int i=0;i<n;i++)
            minHeap.push(make_pair(arr[i],i));
        int prev=minHeap.top().first;
        arr[minHeap.top().second]=++rank;
        minHeap.pop();
        while(!minHeap.empty()){
            int element=minHeap.top().first;
            int index=minHeap.top().second;
            if(prev==element)
                arr[index]=rank;
            else
                arr[index]=++rank;
            prev=element;
            minHeap.pop();
        }
        return arr;
        // to handle duplicates, we can also use a hash map
    }
};