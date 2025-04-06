class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis,
             int& temp) {
        int n = grid.size();
        int m = grid[0].size();
        vis[i][j] = 1;
        temp += grid[i][j];
        // Define directions for horizontal and vertical moves.
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto& d : directions) {
            int nRow = i + d.first;
            int nCol = j + d.second;
            // Check if neighbor is valid, unvisited, and is land.
            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
                grid[nRow][nCol] > 0 && !vis[nRow][nCol]) {
                vis[nRow][nCol] = 1;
                dfs(nRow, nCol, grid, vis, temp);
            }
        }
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == 0 && grid[i][j] > 0) {
                    int temp = 0;
                    dfs(i, j, grid, vis, temp);
                    ans = max(ans, temp);
                }
            }
        }
        return ans;
    }
};