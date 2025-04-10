class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isWater[i][j] == 1) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 0;
                }
            }
        }
        int dis = 0;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int d = q.front().second;
            dis=d;
            q.pop();
            for (auto [dr, dc] : directions) {
                int x = r + dr, y = c + dc;
                if (x >= 0 && x < n && y >= 0 && y < m && isWater[x][y] == 0 && vis[x][y] == -1) {
                    q.push({{x, y}, dis + 1});
                    vis[x][y] = dis+1;
                }
            }
        }
        return vis;
    }
};