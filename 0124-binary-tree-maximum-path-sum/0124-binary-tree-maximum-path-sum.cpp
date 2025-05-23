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
    int maxPathSum(TreeNode* root) {
        int maxsum=INT_MIN;
        height(root,maxsum);
        return maxsum;
    }
    int height(TreeNode* root,int &maxsum){
        if(!root) return 0;
        int leftsum=max(0,height(root->left,maxsum));
        int rightsum=max(0,height(root->right,maxsum));
        maxsum=max(maxsum,root->val+leftsum+rightsum);
        return root->val + max(leftsum,rightsum);
    }
};