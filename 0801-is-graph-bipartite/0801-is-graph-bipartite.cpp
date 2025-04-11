class Solution {
public:
    bool dfs(int node,int col, vector<int>&color, vector<vector<int>>& graph){
        color[node]=col;
        for(auto it:graph[node]){
            if(color[node]==color[it])
                return false;
            else if(color[it]==-1)
                if(dfs(it,!col,color,graph)==false)
                    return false;
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n, -1);

        // M-1 (BFS) (assuming single component)
        // color[0]=0;
        // queue<int>q;
        // q.push(0);
        // while(!q.empty()){
        //     int node=q.front();
        //     q.pop();
        //     for(auto it:graph[node]){
        //         if(color[node]==color[it])
        //             return false;
        //         else if(color[it]==-1){
        //             color[it]=(color[node]==1)?0:1;
        //             q.push(it);
        //         }
        //     }
        // }
        // return true;

        // M-2 (DFS)
        for(int i=0;i<n;i++){
            if(color[i]==-1)
                if(dfs(i,0,color,graph)==false)
                    return false;
        }
        return true;
    }
};