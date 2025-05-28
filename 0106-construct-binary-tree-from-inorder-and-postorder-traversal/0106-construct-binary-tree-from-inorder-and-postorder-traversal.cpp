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
class Solution {
public:
    // Code Story with mik -
    // TreeNode* solve(vector<int> inorder, vector<int> postorder, int s, int e,
    // int& idx,unordered_map<int,int> &mp){
    //     if(s > e)
    //         return NULL;
    //     int i = mp[postorder[idx]];
    //     TreeNode* root = new TreeNode(postorder[idx]);
    //     idx--;
    //     root->right = solve(inorder,postorder,i+1,e,idx,mp);
    //     root->left = solve(inorder,postorder,s,i-1,idx,mp);
    //     return root;
    // }
    // TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    //     int n = inorder.size();
    //     unordered_map<int,int> mp;
    //     for(int i=0;i<n;i++)
    //         mp[inorder[i]] = i;
    //     int idx = n-1;
    //     return solve(inorder,postorder,0,n-1,idx,mp);
    // }

    // Striver -
    TreeNode* solve(vector<int>& inorder, int is, int ie, vector<int>& postorder, int ps, int pe, unordered_map<int, int>& mp) {
        if (ps > pe || is > ie)
            return nullptr;
        TreeNode* root = new TreeNode(postorder[pe]);
        int inRoot = mp[postorder[pe]];
        int numsleft = inRoot - is;
        root->left = solve(inorder, is, inRoot - 1, postorder, ps, ps + numsleft - 1, mp);
        root->right = solve(inorder, inRoot + 1, ie, postorder, ps + numsleft, pe - 1, mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
            mp[inorder[i]] = i;
        return solve(inorder, 0, n - 1, postorder, 0, n - 1, mp);
    }
};