class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // Change all distance‐related types from int to long long
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,greater<pair<long long, int>>>pq;
        vector<vector<vector<long long>>> adj(n);
        for (auto& f : roads) {
            int u = f[0];
            int v = f[1];
            long long w = f[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        vector<long long> dist(n, (long long)1e12), paths(n, 0);
        dist[0] = 0;
        paths[0] = 1;
        pq.push({0LL, 0}); // {dist,node}
        while (!pq.empty()) {
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto it : adj[node]) {
                int n = it[0];
                long long d = it[1];
                long long newDis = dis + d;
                if (newDis < dist[n]) {
                    dist[n] = newDis;
                    pq.push({dist[n], n});
                    paths[n] = paths[node];
                } else if (newDis == dist[n]) {
                    paths[n] = (paths[n] + paths[node]) % 1000000007 ;
                }
            }
        }
        return paths[n - 1] % 1000000007;
    }
};