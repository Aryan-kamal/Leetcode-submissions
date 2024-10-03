class Solution {
public:
    static bool comp(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        // Greedy soln - (similar to n meetings in a room)
        int n = points.size();
        sort(points.begin(), points.end(), comp);
        int cnt = 1,last = points[0][1];
        for (int i = 1; i < n; i++) {
            if (points[i][0] > last) {
                cnt++;
                last = points[i][1];
            }
            // we can skip this else part also -
            else
                continue;
        }
        return cnt;
    }
};