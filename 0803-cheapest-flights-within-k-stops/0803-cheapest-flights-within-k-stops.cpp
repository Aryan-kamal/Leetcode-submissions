class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto& f : flights) {
            int u = f[0];
            int v = f[1];
            int w = f[2];
            adj[u].push_back({v, w});
        }
        vector<int>dis(n,1e8);
        queue<vector<int>>q;
        dis[src]=0;
        q.push({0,src,0}); // {stops,node,distance}
        while(!q.empty()){
            auto arr = q.front();
            int stops = arr[0];
            int node  = arr[1];
            int cost  = arr[2];
            q.pop();
            if(stops>k) continue;
            for(auto it:adj[node]){
                auto [n,d]=it;
                if(d+cost<dis[n]){
                    dis[n]=d+cost;
                    q.push({stops+1,n,d+cost});
                }
            }
        }
        if(dis[dst]==1e8)
            return -1;
        return dis[dst];
    }
};