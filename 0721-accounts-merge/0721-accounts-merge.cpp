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
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<int> parent(n), rankArr(n, 0);
        iota(parent.begin(), parent.end(), 0);
        unordered_map<string, int> mapMailNode;

        // Making DS using union and hash map storing all mails and their parent node {mail,node}
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if (mapMailNode.find(mail) == mapMailNode.end())
                    mapMailNode[mail] = i;
                else
                    unionNodes(i, mapMailNode[mail],parent,rankArr);
            }
        }

        // Now merging all mails acc. to their nodes in 2d vector of strings
        vector<vector<string>> mergedMail(n);
        for (auto it : mapMailNode) {
            string mail = it.first;
            int node = findParent(it.second,parent);
            mergedMail[node].push_back(mail);
        }

        // now creating 2d answer vector containing desired output -
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (mergedMail[i].size() == 0) // empty vector node 
                continue;
            sort(mergedMail[i].begin(), mergedMail[i].end()); // sorting all mails as asked 
            vector<string> temp;
            temp.push_back(accounts[i][0]); // pushing name first 
            for (auto it : mergedMail[i])
                temp.push_back(it); 
            ans.push_back(temp); // then all its mails stored in temp vector of string
        }
        return ans;
    }
};