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

// Shortest path in a grid (using dijkstra) with weights - 
// // Function to find the shortest path using Dijkstra's algorithm in a grid.
// int shortestPath(vector<vector<int>>& grid) {
//     int n = grid.size();
//     if (n == 0) return -1;
//     int m = grid[0].size();
//     // Create a distance grid initialized to a large number.
//     vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
//     dist[0][0] = grid[0][0]; // Start at (0, 0) and include its cost.
//     // Priority queue (min-heap) with elements formatted as (cost, row, col)
//     priority_queue<tuple<int, int, int>, 
//                    vector<tuple<int, int, int>>, 
//                    greater<tuple<int, int, int>>> pq;
//     // Push the starting cell.
//     pq.push({grid[0][0], 0, 0});
//     // Define directions for moving up, down, left, and right.
//     vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
//     // Process the queue until it's empty.
//     while (!pq.empty()) {
//         // Get the element with the lowest cost.
//         auto [cost, row, col] = pq.top();
//         pq.pop();
//         // If we reached the bottom-right cell, we found the shortest path.
//         if (row == n - 1 && col == m - 1) {
//             return cost;
//         }
//         // Explore all four possible neighbors.
//         for (auto& [dr, dc] : directions) {
//             int newRow = row + dr;
//             int newCol = col + dc;
//             // Check if neighbor is within the grid bounds.
//             if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m) {
//                 // Calculate new cost: current path cost + cost of neighbor cell.
//                 int newCost = cost + grid[newRow][newCol];
//                 // If this new cost is lower than the recorded cost, update it.
//                 if (newCost < dist[newRow][newCol]) {
//                     dist[newRow][newCol] = newCost;
//                     pq.push({newCost, newRow, newCol});
//                 }
//             }
//         }
//     }
//     // Return the recorded distance for cell (n-1, m-1).
//     return dist[n-1][m-1];
// }