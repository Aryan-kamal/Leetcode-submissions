class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis,
             int& temp) {
        int n = grid.size();
        int m = grid[0].size();
        vis[i][j] = 1;
        temp++;
        // Define directions for horizontal and vertical moves.
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto& d : directions) {
            int nRow = i + d.first;
            int nCol = j + d.second;
            // Check if neighbor is valid, unvisited, and is land.
            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
                grid[nRow][nCol] == 1 && !vis[nRow][nCol]) {
                vis[nRow][nCol] = 1;
                dfs(nRow, nCol, grid, vis, temp);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == 0 && grid[i][j] == 1) {
                    int temp = 0;
                    dfs(i, j, grid, vis, temp);
                    ans = max(ans, temp);
                }
            }
        }
        return ans;
    }

    int findParent(int node,vector<int>&parent) {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node],parent);
    }

    void unionBySize(int u, int v,vector<int>&parent,vector<int>&sizee) {
        int ulp_u = findParent(u,parent);
        int ulp_v = findParent(v,parent);
        if (ulp_u == ulp_v)
            return;
        if (sizee[ulp_u] < sizee[ulp_v]) {
            parent[ulp_u] = ulp_v;
            sizee[ulp_v] += sizee[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            sizee[ulp_u] += sizee[ulp_v];
        }
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();

        // M-1 brute TLE using maxAreaOfIsland problem -
        // int res=0,ans=0;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         if(grid[i][j]==0)
        //         {
        //             grid[i][j]=1;
        //             res=maxAreaOfIsland(grid);
        //             ans=max(ans,res);
        //             grid[i][j]=0;
        //         }
        //     }
        // }
        // return ans==0?n*n:ans;

        // M-2 using DSU -
        int N = n * n;
        vector<int> parent(N), sizee(N, 1);
        iota(parent.begin(), parent.end(), 0);
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        // step - 1 - connecting nodes 
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 0)
                    continue;
                for (auto& d : directions) {
                    int newr = row + d.first;
                    int newc = col + d.second;
                    if (newr >= 0 && newr < n && newc >= 0 && newc < n && grid[newr][newc] == 1) {
                        int nodeNo = row * n + col;
                        int adjNodeNo = newr * n + newc;
                        unionBySize(nodeNo, adjNodeNo,parent,sizee);
                    }
                }
            }
        }
        // step 2 finding out max size after 0->1
        int mx = 0;
        int cnt=0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1)
                {
                    cnt++; // to keep count of 1
                    continue;
                }
                    
                set<int> components;
                for (auto& d : directions) {
                    int newr = row + d.first;
                    int newc = col + d.second;
                    if (newr >= 0 && newr < n && newc >= 0 && newc < n && grid[newr][newc] == 1)
                        components.insert(findParent(newr * n + newc,parent));
                }
                int sizeTotal = 0;
                for (auto it : components)
                    sizeTotal += sizee[it];

                mx = max(mx, sizeTotal + 1);
            }
        }
        
        // for (int cellNo = 0; cellNo < n * n; cellNo++)
        //     mx = max(mx, sizee[findParent(cellNo,parent)]);
        // return mx;
        
        return cnt==N ? N : mx;
    }
};