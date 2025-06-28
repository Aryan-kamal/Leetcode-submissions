class Solution {
public:
    int DFS(unordered_map<int, vector<int>>& adj, int curr, vector<bool>& hasApple, vector<bool>& visited) {
        visited[curr] = true;
        int time = 0;
        for (int& child : adj[curr]) {
            if (visited[child]) 
                continue;
            int timeFromChildren = DFS(adj, child, hasApple, visited);
            if (timeFromChildren || hasApple[child])
                time += 2 + timeFromChildren;
        }
        return time;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int, vector<int>> adj;
        for (auto& vec : edges) {
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n, false);
        return DFS(adj, 0, hasApple, visited);
    }
};
