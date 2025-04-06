class Solution {
public:
    // void bfs(int i, int j, vector<vector<char>>& grid,
    //          vector<vector<int>>& vis) {
    //     int n = grid.size();
    //     int m = grid[0].size();
    //     vis[i][j] = 1;
    //     queue<pair<int, int>> q;
    //     q.push({i, j});
    //     // Define directions for horizontal and vertical moves.
    //     vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0,
    //     1}}; while (!q.empty()) {
    //         int row = q.front().first;
    //         int col = q.front().second;
    //         q.pop();

    //         for (auto& d : directions) {
    //             int nRow = row + d.first;
    //             int nCol = col + d.second;
    //             // Check if neighbor is valid, unvisited, and is land.
    //             if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
    //                 grid[nRow][nCol] == '1' && !vis[nRow][nCol]) {
    //                 vis[nRow][nCol] = 1;
    //                 q.push({nRow, nCol});
    //             }
    //         }
    //     }
    // }

    void dfs(int i, int j, vector<vector<char>>& grid,
             vector<vector<int>>& vis) {
        int n = grid.size();
        int m = grid[0].size();
        vis[i][j] = 1;
        // Define directions for horizontal and vertical moves.
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto& d : directions) {
            int nRow = i + d.first;
            int nCol = j + d.second;
            // Check if neighbor is valid, unvisited, and is land.
            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
                grid[nRow][nCol] == '1' && !vis[nRow][nCol]) {
                vis[nRow][nCol] = 1;
                dfs(nRow, nCol, grid, vis);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == 0 && grid[i][j] == '1') {
                    cnt++;
                    dfs(i, j, grid, vis);
                }
            }
        }
        return cnt;
    }
};