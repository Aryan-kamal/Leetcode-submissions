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
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> parent(n), rankArr(n, 0);
        iota(parent.begin(), parent.end(), 0);
        int minEdges = 0;
        int extraEdges = 0;

        // finding extra edges (using MST concept) -
        for (auto& e : connections) {
            int u = e[0];
            int v = e[1];
            if (findParent(u, parent) != findParent(v, parent))
                unionNodes(u, v, parent, rankArr);
            else
                extraEdges++;
        }

        // Finding number of components  
        for (int i = 0; i < n; i++)
            if (findParent(i, parent) == i)
                minEdges++;

        minEdges--; // minimum edges required to connect all components 
        return (minEdges <= extraEdges) ? minEdges : -1;
    }
};