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

// slightly modifies striver's appraoch -
// instead of making third variable we can also update the middle variable when
// there is a 2nd violation
class Solution {
public:
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    TreeNode* prev = NULL;
    void inorder(TreeNode* root) {
        if (!root)
            return;
        inorder(root->left);
        if (prev != NULL && prev->val > root->val) {
            if (first == NULL) {
                first = prev;  // first value to be swapped
                second = root; // keeping this incase of values to be swapped
                               // are ajacent ie 2nd case
            } else
                second = root; // 2nd voilation hence second value to be swapped
        }
        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        prev = new TreeNode(INT_MIN);
        inorder(root);
        swap(first->val, second->val);
    }
};

// Striver - 
// class Solution {
// public:
//     TreeNode* first = NULL;
//     TreeNode* second = NULL;
//     TreeNode* last = NULL;
//     TreeNode* prev = NULL;
//     void inorder(TreeNode* root) {
//         if (!root)
//             return;
//         inorder(root->left);

//         if (prev != NULL && prev->val > root->val) {
//             if (first == NULL) {
//                 first = prev;
//                 second = root;
//             } else
//                 last = root;
//         }
//         prev = root;
//         inorder(root->right);
//     }
//     void recoverTree(TreeNode* root) {
//         prev = new TreeNode(INT_MIN);
//         inorder(root);
//         if (first && last) {
//             int temp = first->val;
//             first->val = last->val;
//             last->val = temp;
//         } else {
//             int temp = first->val;
//             first->val = second->val;
//             second->val = temp;
//         }
//     }
// };