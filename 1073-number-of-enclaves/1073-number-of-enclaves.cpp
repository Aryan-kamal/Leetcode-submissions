class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int i,
             int j) {
        int n = grid.size();
        int m = grid[0].size();
        vis[i][j] = 1;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto d : directions) {
            int ii = i + d.first;
            int jj = j + d.second;
            if (ii >= 0 && ii < n && jj >= 0 && jj < m &&
                grid[ii][jj] == 1 && vis[ii][jj] == 0) {
                vis[ii][jj] = 1;
                dfs(grid, vis, ii, jj);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        // M-1 (using Surrounded region problem approach) (DFS)
        int n = grid.size();
        int m = grid[0].size();
        int cnt=0,ones=0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 1 && vis[0][j] == 0)
                dfs(grid, vis, 0, j);
            if (grid[n - 1][j] == 1 && vis[n - 1][j] == 0)
                dfs(grid, vis, n - 1, j);
        }
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1 && vis[i][0] == 0)
                dfs(grid, vis, i, 0);
            if (grid[i][m - 1] == 1 && vis[i][m - 1] == 0)
                dfs(grid, vis, i, m - 1);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(grid[i][j]==1 && vis[i][j] == 0)
                    cnt++;
            }
        }
        return cnt;
    }
};

// M-2 (similar approach) Striver (using BFS)
// int numberOfEnclaves(vector<vector<int>> &grid) {
//     queue<pair<int,int>> q; 
//     int n = grid.size(); 
//     int m = grid[0].size(); 
//     int vis[n][m] = {0}; 
//     // traverse boundary elements
//     for(int i = 0;i<n;i++) {
//         for(int j = 0;j<m;j++) {
//             // first row, first col, last row, last col 
//             if(i == 0 || j == 0 || i == n-1 || j == m-1) {
//                 // if it is a land then store it in queue
//                 if(grid[i][j] == 1) {
//                     q.push({i, j}); 
//                     vis[i][j] = 1; 
//                 }
//             }
//         }
//     }
    
//     int delrow[] = {-1, 0, +1, 0};
//     int delcol[] = {0, +1, +0, -1}; 
    
//     while(!q.empty()) {
//         int row = q.front().first; 
//         int col = q.front().second; 
//         q.pop(); 
        
//         // traverses all 4 directions
//         for(int i = 0;i<4;i++) {
//             int nrow = row + delrow[i];
//             int ncol = col + delcol[i]; 
//             // check for valid coordinates and for land cell
//             if(nrow >=0 && nrow <n && ncol >=0 && ncol < m 
//             && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
//                 q.push({nrow, ncol});
//                 vis[nrow][ncol] = 1; 
//             }
//         }
        
//     }
//     int cnt = 0;
//     for(int i = 0;i<n;i++) {
//         for(int j = 0;j<m;j++) {
//             // check for unvisited land cell
//             if(grid[i][j] == 1 & vis[i][j] == 0) 
//                 cnt++; 
//         }
//     }
//     return cnt; 
// }