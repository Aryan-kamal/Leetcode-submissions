class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> maxHeap;
        vector<vector<int>>ans;
        for(int i=0;i<points.size();i++)
        {
            int x=points[i][0];
            int y=points[i][1];
            int dist=pow(x,2) + pow(y,2);
            maxHeap.push(make_pair(dist,make_pair(x,y)));
            if(maxHeap.size()>k)
                maxHeap.pop(); 
        }
        while(!maxHeap.empty()){
            int x=maxHeap.top().second.first;
            int y=maxHeap.top().second.second;
            vector<int>point={x,y};
            ans.push_back(point);
            maxHeap.pop();
        }
        return ans;
    }
};