class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& ans,
             vector<vector<int>>& vis, int color, int orig) {
        int n = grid.size(), m = grid[0].size();
        vis[i][j] = 1;

        bool isBorder = false;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto [dx, dy] : directions) {
            int x = i + dx, y = j + dy;
            if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] != orig)
                isBorder = true;
            else if (!vis[x][y])
                dfs(x, y, grid, ans, vis, color, orig);
        }

        if (isBorder) {
            ans[i][j] = color;
        }
    }

    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans = grid;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        dfs(row, col, grid, ans, vis, color, grid[row][col]);
        return ans;
    }
};

// TLE (idk how)
// class Solution {
// public:
//     void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& ans,int color) {
//         int n = grid.size();
//         int m = grid[0].size();
//         ans[i][j] = color;
//         int cnt=0;
//         vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
//         for (auto d : directions) {
//             int ii = i + d.first;
//             int jj = j + d.second;
//             if (ii >= 0 && ii < n && jj >= 0 && jj < m && grid[ii][jj] == grid[i][j]) {
//                 cnt++;
//                 if(ans[ii][jj] != color){
//                     ans[ii][jj] = color;
//                     dfs(ii, jj, grid, ans, color);
//                 } 
//             }
//         }
//         if(cnt==4)
//             ans[i][j]=grid[i][j];
//     }

//     vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
//         vector<vector<int>> ans=grid;
//         dfs(row, col, grid, ans, color);
//         return ans;
//     }
// };