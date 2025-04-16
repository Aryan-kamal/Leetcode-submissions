class Solution {
public:
    // Minimum max elevation in a path
    // Here we have to find the path which has lowest maximum cell value
    // Straightforward Djikstra algo 
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        // elevation[i][j] = min possible maximum elevation along a path to (i,j)
        vector<vector<int>> elevation(n, vector<int>(n, 1e8));
    
        // Min-heap of {bottleneck, {row, col}}
        priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<>> pq;
        
        // Start at (0,0) with bottleneck = grid[0][0] (can also initialize elevation[0][0]=0 and push {0,{0,0}})
        elevation[0][0] = grid[0][0];
        pq.push({elevation[0][0], {0, 0}});
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!pq.empty()) {
            auto [currBottleneck, pos] = pq.top();
            int row = pos.first, col = pos.second;
            pq.pop();
            // If we reached the target, return its bottleneck
            if (row == n - 1 && col == n - 1)
                return currBottleneck;
            for (auto &d : directions) {
                int nr = row + d.first;
                int nc = col + d.second;
                if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                    // The path to (nr,nc) has maximum elevation = max(current path's max, neighbor's cell elevation)
                    int newBottleneck = max(currBottleneck, grid[nr][nc]);
                    // If this path is better (lower maximum) than previously known
                    if (newBottleneck < elevation[nr][nc]) {
                        elevation[nr][nc] = newBottleneck;
                        pq.push({newBottleneck, {nr, nc}});
                    }
                }
            }
        }
        // Should never get here if grid is valid
        return 0;
    }
};