class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int r = entrance[0], c = entrance[1];
        int n = maze.size();
        int m = maze[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q; // ((row, col), steps)
        q.push({{r, c}, 0});
        vis[r][c] = 1;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!q.empty()) {
            auto [row_col, steps] = q.front();
            auto [row, col] = row_col;
            q.pop();
            if ((row!=r || col!=c) && (row == 0 || row == n-1 || col == 0 || col == m-1)) 
                return steps;
            
            for (auto [dr, dc] : directions) {
                int nr = row + dr;
                int nc = col + dc;
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && maze[nr][nc] == '.') {
                    q.push({{nr, nc}, steps + 1});
                    vis[nr][nc] = 1;
                }
            }
        }
        return -1;
    }
};
