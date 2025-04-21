class Solution {
public:
    // void dfs(vector<vector<int>> &adj,vector<int> &vis,int node){
    //     vis[node]=1;
    //     for(auto it:adj[node]){
    //         if(!vis[it])
    //             dfs(adj,vis,it);
    //     }
    // }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        // M-1 -
        // vector<vector<int>> adj(n);
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         if (isConnected[i][j] == 1 && i != j) {
        //             adj[i].push_back(j);
        //             adj[j].push_back(i);
        //         }
        //     }
        // }
        // int cnt=0;
        // vector<int> vis(n, 0);
        // for (int i = 0; i < n; i++) {
        //     if (vis[i] == 0) {
        //         cnt++;
        //         dfs(adj, vis, i);
        //     }
        // }
        // return cnt;


        // M-2 - 
        vector<int> parent(n), rankArr(n, 0);
        iota(parent.begin(), parent.end(), 0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1)
                    unionNodes(i,j,parent,rankArr);
            }
        }
        // Use this method only 
        int cnt=0;
        for(int i=0;i<n;i++){
            if(findParent(i,parent)==i)
                cnt++;
        }
        return cnt;
    }
    int findParent(int x, vector<int>& parent) {
        if (parent[x] == x) return x;
        return parent[x] = findParent(parent[x], parent);
    }
    
    // Unions the sets containing a and b (by rank)
    void unionNodes(int a, int b, vector<int>& parent, vector<int>& rankArr) {
        a = findParent(a, parent);
        b = findParent(b, parent);
        if (a == b) return;
        if (rankArr[a] < rankArr[b]) {
            parent[a] = b;
        } else if (rankArr[b] < rankArr[a]) {
            parent[b] = a;
        } else {
            parent[b] = a;
            rankArr[a]++;
        }
    }
};