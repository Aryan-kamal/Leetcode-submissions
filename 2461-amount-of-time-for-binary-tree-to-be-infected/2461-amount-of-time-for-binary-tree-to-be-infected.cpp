/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // M-1 BFS approach + mark parent 
    TreeNode* markParents(TreeNode* root,unordered_map<TreeNode*, TreeNode*>& parent,int start) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* target = nullptr;
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr->val == start)
                target = curr;

            if (curr->left) {
                parent[curr->left] = curr;
                q.push(curr->left);
            }

            if (curr->right) {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
        return target;
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent;
        TreeNode* target = markParents(root, parent, start);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;

        int time = -1;

        while (!q.empty()) {
            int size = q.size();
            time++;

            for (int i = 0; i < size; ++i) {
                TreeNode* curr = q.front();
                q.pop();

                if (curr->left && !visited[curr->left]) {
                    visited[curr->left] = true;
                    q.push(curr->left);
                }

                if (curr->right && !visited[curr->right]) {
                    visited[curr->right] = true;
                    q.push(curr->right);
                }

                if (parent[curr] && !visited[parent[curr]]) {
                    visited[parent[curr]] = true;
                    q.push(parent[curr]);
                }
            }
        }
        return time;
    }
};



// DFS approach - 
// void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent, int start, TreeNode*& target) {
//     queue<TreeNode*> q;
//     q.push(root);

//     while (!q.empty()) {
//         TreeNode* curr = q.front();
//         q.pop();

//         if (curr->val == start)
//             target = curr;

//         if (curr->left) {
//             parent[curr->left] = curr;
//             q.push(curr->left);
//         }

//         if (curr->right) {
//             parent[curr->right] = curr;
//             q.push(curr->right);
//         }
//     }
// }

// //similar code to find max height 
// int dfs(TreeNode* node, unordered_map<TreeNode*, TreeNode*>& parent, unordered_set<TreeNode*>& visited) {
//     if (!node || visited.count(node)) 
//         return 0;

//     visited.insert(node);

//     int left = dfs(node->left, parent, visited);
//     int right = dfs(node->right, parent, visited);
//     int up = dfs(parent[node], parent, visited);

//     return 1 + max({left, right, up});
// }

// int amountOfTime(TreeNode* root, int start) {
//     unordered_map<TreeNode*, TreeNode*> parent;
//     TreeNode* target = nullptr;

//     // mark parents and find target node
//     markParents(root, parent, start, target);

//     unordered_set<TreeNode*> visited;

//     // run dfs from target to find max infection time
//     return dfs(target, parent, visited) - 1;
// }