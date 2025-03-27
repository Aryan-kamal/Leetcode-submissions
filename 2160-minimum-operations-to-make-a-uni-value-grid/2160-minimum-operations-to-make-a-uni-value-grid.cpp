class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int>sortedArray;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                sortedArray.push_back(grid[i][j]);
        }
        int cnt=0;
        sort(sortedArray.begin(), sortedArray.end());
        int ele=sortedArray[(m*n)/2];
        for(int i=0;i<n*m;i++){
            if((sortedArray[i]%x)==(ele%x))
                cnt+=abs(ele-sortedArray[i])/x;
            else{
                cnt=-1;
                break;
            }
        }
        return cnt;
    }
};