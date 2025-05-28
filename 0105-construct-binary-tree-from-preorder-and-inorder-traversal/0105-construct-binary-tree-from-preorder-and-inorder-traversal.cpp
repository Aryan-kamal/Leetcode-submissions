/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mpp;
        for (int i = 0; i < inorder.size(); i++)
            mpp[inorder[i]] = i;
        
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mpp);
    }

    TreeNode* buildTree(vector<int>& preorder, int ps, int pe, vector<int>& inorder, int is, int ie, unordered_map<int, int>& mpp) {
        if (ps > pe || is > ie)
            return nullptr;
        
        TreeNode* node = new TreeNode(preorder[ps]);
        int root_ind = mpp[node->val];
        int left_data = root_ind - is; // Number of elements in the left subtree
        
        node->left = buildTree(preorder, ps + 1, ps + left_data, inorder, is, root_ind - 1, mpp);
        node->right = buildTree(preorder, ps + left_data + 1, pe, inorder, root_ind + 1, ie, mpp);
        
        return node;
    }
};