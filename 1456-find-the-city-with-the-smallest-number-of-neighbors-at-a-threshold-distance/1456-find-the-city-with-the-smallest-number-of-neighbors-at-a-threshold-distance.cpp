class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Create adjancy matrix
        vector<vector<int>> mat(n, vector<int>(n, 1e8));
        for (int i = 0; i < n; i++)
            mat[i][i] = 0;
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            mat[u][v] = w;
            mat[v][u] = w;
        }

        // Floyd Warshall algo -
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    // only relax if i→k and k→j are both not “infinite”
                    if (mat[i][k] != 1e8 && mat[k][j] != 1e8) {
                        mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                    }
                }
            }
        }
        
        // find city-
        int ans=0,mini=n;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(mat[i][j]<=distanceThreshold)
                    cnt++;
            }
            if(cnt<=mini){
                mini=cnt;
                ans=i;
            }
        }
        return ans;
    }
};