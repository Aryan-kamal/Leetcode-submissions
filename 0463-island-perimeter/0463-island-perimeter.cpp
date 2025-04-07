class Solution {
public:
    // void dfs(int i, int j, vector<vector<int>>& grid,vector<vector<int>>&vis, int &ans) {
    //     int n = grid.size();
    //     int m = grid[0].size();
    //     vis[i][j] = 1;
    //     int adjacent = 0;

    //     // Define directions for horizontal and vertical moves.
    //     vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0,1}};

    //     // Single loop to count adjacent lands and perform DFS.
    //     for (auto& d : directions) {
    //         int nRow = i + d.first;
    //         int nCol = j + d.second;

    //         // Check if neighbor is within bounds and is land.
    //         if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
    //         grid[nRow][nCol] == 1) {
    //             adjacent++; // Count this adjacent land cell.
    //             // If neighbor hasn't been visited, do DFS.
    //             if (!vis[nRow][nCol])
    //                 dfs(nRow, nCol, grid, vis, ans);
    //         }
    //     }
    //     // Each cell contributes (4 - number of adjacent land cells) to the perimeter. 
    //     ans += (4 - adjacent);
    // }

    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        // M-1 BFS / DFS -
        // vector<vector<int>> vis(n, vector<int>(m, 0));
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         if (grid[i][j] == 1 && !vis[i][j]) {
        //             dfs(i, j, grid, vis, ans);
        //             return ans;
        //         }
        //     }
        // }

        // M-2 array -
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    if (i + 1 == n || grid[i + 1][j] == 0)
                        ans++;
                    if (i - 1 < 0 || grid[i - 1][j] == 0)
                        ans++;
                    if (j + 1 == m || grid[i][j + 1] == 0)
                        ans++;
                    if (j - 1 < 0 || grid[i][j - 1] == 0)
                        ans++;
                }
            }
        }

        return ans;
    }
};