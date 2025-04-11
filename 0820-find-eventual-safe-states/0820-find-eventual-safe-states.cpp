class Solution {
public:
    // bool dfs(int node, vector<int>& vis, vector<int>& pathvis,vector<vector<int>>& adj,vector<int>&ans) {
    //     vis[node] = 1;
    //     pathvis[node] = 1;
    //     for (auto it : adj[node]) {
    //         if (vis[it] == 0) {
    //             if (dfs(it, vis, pathvis, adj, ans))
    //                 return true;
    //         }
    //         else if (pathvis[it] == 1)
    //             return true;
    //     }
    //     pathvis[node] = 0;
    //     ans.push_back(node);
    //     return false;
    // }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();

        // M-1 (using concept of detecting cycle in directed graph using DFS) -
        // vector<int> vis(V, 0);
        // vector<int> pathvis(V, 0);
        // vector<int>ans;
        // for (int i = 0; i < V; i++) {
        //     if (vis[i] == 0)
        //         dfs(i, vis, pathvis, graph,ans);
        // }
        // sort(ans.begin(),ans.end());
        // return ans;

        // M-2 (Topo sort) -
        vector<int> indegree(V, 0);
        vector<vector<int>> revAdj(V);
        for(int i=0;i<V;i++){
            for(auto it:graph[i])
            {
                revAdj[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int>q;
        vector<int>topo;
        for(int i=0;i<V;i++)
            if(indegree[i]==0)
                q.push(i);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:revAdj[node]){
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        sort(topo.begin(),topo.end());
        return topo;
    }
};
