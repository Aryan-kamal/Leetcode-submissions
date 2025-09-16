class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        // M-1 Brute (n^3) (will pass)
        // int cnt = 0;
        // for (auto first : points) {
        //     int x1 = first[0], y1 = first[1];
        //     for (auto second : points) {
        //         if (first == second)
        //             continue;
        //         int x2 = second[0], y2 = second[1];
        //         if (x2 <= x1 && y2 >= y1) { // 1st condn done
        //             int flag = 0;
        //             for (auto third : points) {
        //                 if (third == first || third == second)
        //                     continue;
        //                 int x3 = third[0], y3 = third[1];
        //                 if (x3 <= x1 && x3 >= x2 && y3 >= y1 && y3 <= y2) { // 2nd condn done
        //                     flag = 1;
        //                     break;
        //                 }
        //             }
        //             if (flag == 0)
        //                 cnt++;
        //         }
        //     }
        // }
        // return cnt;

        // M-2 Optimal n^2 using sorting
        int n = points.size();
        // Sort: x ascending, if x same then sort as y descending
        auto lambda = [](vector<int>& point1, vector<int>& point2) {
            if (point1[0] == point2[0]) 
                return point1[1] > point2[1];
            return point1[0] < point2[0];
        };
        sort(points.begin(), points.end(), lambda);
        int result = 0;
        for (int i = 0; i < n; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1]; // upper left
            int bestY = INT_MIN;
            for (int j = i + 1; j < n; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1]; // lower right
                // Condition: (x2, y2) must be above (x1, y1)
                if (y2 > y1) // not lower right
                    continue;
                if (y2 > bestY) {
                    result++;
                    bestY = y2;
                }
            }
        }
        return result;
    }
};