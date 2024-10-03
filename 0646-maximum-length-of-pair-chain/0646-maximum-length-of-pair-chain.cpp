class Solution {
public:
    static bool comp(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        // Simple greedy approch just like n meeting in 1 room -
        int n = pairs.size();
        sort(pairs.begin(), pairs.end(), comp);
        int cnt = 1,freeTime = pairs[0][1];
        for (int i = 1; i < n; i++) {
            if (pairs[i][0] > freeTime) {
                cnt++;
                freeTime = pairs[i][1];
            }
        }
        return cnt;
    }
};