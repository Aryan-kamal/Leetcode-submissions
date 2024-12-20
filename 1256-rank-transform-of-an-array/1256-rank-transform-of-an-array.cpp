class Solution {
public:
    // M-1 (using binary search) (in notebook)
    // M-2 (using heap)
    // vector<int> arrayRankTransform(vector<int>& arr) {
    //     int n=arr.size();
    //     if(n==0)
    //         return {};
    //     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    //     int rank=0;
    //     for(int i=0;i<n;i++)
    //         minHeap.push(make_pair(arr[i],i));
    //     int prev=minHeap.top().first;
    //     arr[minHeap.top().second]=++rank;
    //     minHeap.pop();
    //     while(!minHeap.empty()){
    //         int element=minHeap.top().first;
    //         int index=minHeap.top().second;
    //         if(prev!=element)
    //             rank++;
    //         arr[index]=rank;
    //         prev=element;
    //         minHeap.pop();
    //     }
    //     return arr;
    //     // to handle duplicates, we can also use a hash map
    // }
    // M-3 (using hash and set)
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if(n == 0)
            return {};
        set<int> uniqueElements(arr.begin(), arr.end()); // to store unique elements in sorted order
        vector<int> ans; // vector to store the rank transformation of the input array 
        unordered_map<int, int> ranks; // to store the rank of each unique element
        int rank = 1;
        // Assign ranks to each unique element in the set
        for (const int &ele : uniqueElements)
            ranks[ele] = rank++;
        
        // For each element in the input array, find its rank and store it in the result vector
        for (int &ele : arr)
            ans.push_back(ranks[ele]);
        return ans;
    }
};