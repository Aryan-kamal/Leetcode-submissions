class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> effort(n, vector<int>(m, 1e8));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> q;
        q.push({0, {0, 0}});
        effort[0][0] = 0;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!q.empty()) {
            int currEffort = q.top().first;
            int row = q.top().second.first;
            int col = q.top().second.second;
            if(row==n-1 && col == m-1)
                return currEffort;
            q.pop();
            for (auto& d : directions) {
                int nRow = row + d.first;
                int nCol = col + d.second;
                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m){ //  out of bound validity
                    // The effort for this step is determined by the absolute difference.
                    int stepEffort = abs(heights[nRow][nCol] - heights[row][col]);
                    // The effort to reach the new cell is the maximum effort encountered along the path.
                    int newEffort = max(currEffort, stepEffort);
                    // If this new effort is less than the recorded effort for new cell, update it.
                    if (newEffort < effort[nRow][nCol]) {
                        effort[nRow][nCol] = newEffort;
                        q.push({newEffort, {nRow, nCol}});
                    }
                }
            }
        }
        return 0;
    }
};