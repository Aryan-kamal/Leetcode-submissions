/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
// class Solution {
// public:
//     // Striver's Approach -
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         int n = preorder.size();
//         unordered_map<int, int> mpp;
//         for (int i = 0; i < inorder.size(); i++)
//             mpp[inorder[i]] = i;
//         return buildTree(preorder, 0, n - 1, inorder, 0, n - 1, mpp);
//     }

//     TreeNode* buildTree(vector<int>& preorder, int ps, int pe,vector<int>& inorder, int is, int ie,unordered_map<int, int>& mpp) {
//         if (ps > pe || is > ie)
//             return nullptr;
//         TreeNode* node = new TreeNode(preorder[ps]);
//         int root_ind = mpp[node->val];
//         int left_data = root_ind - is; // Number of elements in the left subtree
//         node->left = buildTree(preorder, ps + 1, ps + left_data, inorder, is,root_ind - 1, mpp);
//         node->right = buildTree(preorder, ps + left_data + 1, pe, inorder,root_ind + 1, ie, mpp);
//         return node;
//     }
// };

// 2 Approaches of Code story with mik
// Basic Approach (Without using Hash map) -
//     TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start,
//     int end, int& idx) {
//         if(start > end)
//             return NULL;
//         int rootVal = preorder[idx];
//         int i = start;
//         for(; i <= end; i++)
//             if(inorder[i] == rootVal)
//                 break;
//         idx++;
//         TreeNode* root = new TreeNode(rootVal);
//         root->left  = solve(preorder, inorder, start, i-1, idx);
//         root->right = solve(preorder, inorder, i+1, end, idx);
//         return root;
//     }

//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         int n = preorder.size();
//         int idx = 0;
//         return solve(preorder, inorder, 0, n-1, idx);
//     }

// Optimized approach by using map to find index of root in inorder array -
class Solution {
public:
    TreeNode* construct(vector<int>& preorder, vector<int>& inorder, int l,int r, int& idx, unordered_map<int, int>& mp) {
        if (l > r)
            return NULL;
        int rootVal = preorder[idx];
        idx++;
        int i = mp[rootVal];
        TreeNode* root = new TreeNode(rootVal);
        root->left = construct(preorder, inorder, l, i - 1, idx, mp);
        root->right = construct(preorder, inorder, i + 1, r, idx, mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        int n = preorder.size();
        for (int i = 0; i < n; i++)
            mp[inorder[i]] = i;
        int idx = 0;
        return construct(preorder, inorder, 0, n - 1, idx, mp);
    }
};