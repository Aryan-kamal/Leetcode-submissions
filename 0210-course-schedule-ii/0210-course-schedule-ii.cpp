class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int N = numCourses;
        vector<vector<int>> adj(N);
        for (auto it : prerequisites)
            adj[it[1]].push_back(it[0]);

        vector<int> indegree(N, 0);
        for (int i = 0; i < N; i++) {
            for (auto it : adj[i])
                indegree[it]++;
        }
        queue<int> q;
        vector<int> topo;
        for (int i = 0; i < N; i++)
            if (indegree[i] == 0)
                q.push(i);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }
        return (topo.size() == N) ? topo : vector<int>{};
    }
};