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
    // M-1 (O(n)) (any Traversal)

    // M-2 (logn)^2 
    int countNodes(TreeNode* root) {
        if(!root) 
            return 0;
        int lh=findLeftHeight(root);
        int rh=findRightHeight(root);
        if(lh==rh)
            return (1<<lh)-1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
    int findLeftHeight(TreeNode* root){
        int height=0;
        while(root){
            height++;
            root=root->left;
        }
        return height;
    }
    int findRightHeight(TreeNode* root){
        int height=0;
        while(root){
            height++;
            root=root->right;
        }
        return height;
    }
};