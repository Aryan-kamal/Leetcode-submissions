class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if (grid[0][0] != 0 || grid[n - 1][m - 1] != 0)
            return -1;
        if(n == 1 && m == 1)
            return 1;
        vector<vector<int>> dis(n, vector<int>(m, 1e8));
        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0, 0}});
        dis[0][0] = 1;
        // Define directions for horizontal and vertical moves.
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0},   {0, -1},
                                             {0, 1},  {-1, -1}, {-1, 1},
                                             {1, -1}, {1, 1}};
        while (!q.empty()) {
            int dist = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            for (auto& d : directions) {
                int nRow = row + d.first;
                int nCol = col + d.second;
                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
                    grid[nRow][nCol] == 0 && dist + 1 < dis[nRow][nCol]) {
                    if (nRow == n - 1 && nCol == m - 1)
                        return dist + 1;
                    dis[nRow][nCol] = dist + 1;
                    q.push({dist + 1, {nRow, nCol}});
                }
            }
        }
        return -1;
    }
};