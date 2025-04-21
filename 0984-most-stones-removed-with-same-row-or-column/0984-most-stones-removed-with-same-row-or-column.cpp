class Solution {
public:
    int findParent(int x, vector<int>& parent) {
        if (parent[x] == x)
            return x;
        return parent[x] = findParent(parent[x], parent);
    }

    // Unions the sets containing a and b (by rank)
    void unionNodes(int a, int b, vector<int>& parent, vector<int>& rankArr) {
        a = findParent(a, parent);
        b = findParent(b, parent);
        if (a == b)
            return;
        if (rankArr[a] < rankArr[b]) {
            parent[a] = b;
        } else if (rankArr[b] < rankArr[a]) {
            parent[b] = a;
        } else {
            parent[b] = a;
            rankArr[a]++;
        }
    }
    
    void dfs(vector<vector<int>>& stones, int index, vector<bool>& vis) {
        vis[index] = true;
        int n=stones.size();
        for(int i = 0; i<n; i++)
            if(!vis[i] && ((stones[i][0] == stones[index][0]) || (stones[i][1] == stones[index][1])))
                dfs(stones, i, vis);
    }

    int removeStones(vector<vector<int>>& stones) {
        int n =stones.size();

        // M-1 DSU - 
        // int maxRow = 0, maxCol = 0;
        // for (auto& s : stones) {
        //     maxRow = max(maxRow, s[0]);
        //     maxCol = max(maxCol, s[1]);
        // }
        // int R = maxRow + 1;
        // int C = maxCol + 1;
        // int N = R + C; // total DSU nodes
        // vector<int> parent(N), rankArr(N, 0);
        // iota(parent.begin(), parent.end(), 0);

        // // 1) Union row-node r with column-node (R + c)
        // unordered_map<int, int> hash;
        // for (auto& s : stones) {
        //     int r = s[0];
        //     int c = s[1] + R;
        //     unionNodes(r, c, parent, rankArr);
        //     hash[c]=1;
        //     hash[r]=1;
        // }
        // int compo = 0;
        // for (auto it : hash) {
        //     if (findParent(it.first,parent)==it.first)
        //         compo++;
        // }
        // return n - compo;
        
        //  ---------------------------------------------------------------------------
        // M-2 DFS - 
        vector<bool> vis(n, false);
        int count = 0;
        for(int i = 0; i<n; i++) {
            if(vis[i])
                continue;
            dfs(stones, i, vis);
            count++;
        }
        return n - count;
    }
};