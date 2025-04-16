class Solution {
public:
    bool check(vector<vector<int>>& distNearestThief, int sf) {
        int n=distNearestThief.size();
        queue<pair<int, int>> que;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        // 0,0 --> n-1, n-1
        que.push({0, 0});
        visited[0][0] = true;
        if (distNearestThief[0][0] < sf)
            return false;
        while (!que.empty()) {
            int curr_i = que.front().first;
            int curr_j = que.front().second;
            que.pop();
            if (curr_i == n - 1 && curr_j == n - 1)
                return true;
            for (auto d : directions) {
                int new_i = curr_i + d.first;
                int new_j = curr_j + d.second;
                if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < n &&
                    visited[new_i][new_j] != true) {
                    if (distNearestThief[new_i][new_j] < sf) 
                        continue; // reject this cell
                    que.push({new_i, new_j});
                    visited[new_i][new_j] = true;
                }
            }
        }
        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        // Step 1 - make manhaton distance grid
        vector<vector<int>> safe(n, vector<int>(n, 1e8));
        // Queue for multi-source BFS.
        // Each queue entry is a pair: {row, col} along with current distance.
        queue<pair<int, int>> q;
        // Starting from every thief cell (cell value 1)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    safe[i][j] = 0; // A thief has zero distance to itself.
                    q.push({i, j});
                }
            }
        }
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        // Execute BFS to update the safeness factor for each cell.
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            int currentDist = safe[row][col];
            for (auto& d : directions) {
                int newRow = row + d.first;
                int newCol = col + d.second;
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n) {
                    // The new distance is one more than the current cell's distance.
                    if (currentDist + 1 < safe[newRow][newCol]) {
                        safe[newRow][newCol] = currentDist + 1;
                        q.push({newRow, newCol});
                    }
                }
            }
        }

        // Step-2 Apply binary search on SF
        int l = 0;
        int r = 400;
        int result = 0;
        while (l <= r) {
            int mid_sf = l + (r - l) / 2;
            if (check(safe, mid_sf)) {
                result = mid_sf;
                l = mid_sf + 1;
            }
            else
                r = mid_sf - 1;
        }
        return result;
    }
};