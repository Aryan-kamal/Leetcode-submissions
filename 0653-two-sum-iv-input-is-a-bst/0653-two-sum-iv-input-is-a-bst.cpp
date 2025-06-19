// 1 class but 2 stacks -
class Solution {
    public :
    stack<TreeNode*> leftStack, rightStack;

    void pushLeft(TreeNode* node) {
        while (node) {
            leftStack.push(node);
            node = node->left;
        }
    }

    void pushRight(TreeNode* node) {
        while (node) {
            rightStack.push(node);
            node = node->right;
        }
    }

    int getNextLeft() {
        TreeNode* node = leftStack.top();
        leftStack.pop();
        pushLeft(node->right);
        return node->val;
    }

    int getNextRight() {
        TreeNode* node = rightStack.top();
        rightStack.pop();
        pushRight(node->left);
        return node->val;
    }

    bool findTarget(TreeNode* root, int k) {
        if (!root)
            return false;

        pushLeft(root);  // Initialize left stack (in-order)
        pushRight(root); // Initialize right stack (reverse in-order)

        int i = getNextLeft();
        int j = getNextRight();

        while (i < j) {
            int sum = i + j;
            if (sum == k)
                return true;
            else if (sum < k)
                i = getNextLeft();
            else
                j = getNextRight();
        }
        return false;
    }
};

// Striver's aproach (using 2 classes but single stack)-
// class BSTIterator{
//     stack<TreeNode*> st;
//     bool right;
//     void push(TreeNode* root){
//         while(root){
//             st.push(root);
//             if(!right){
//                 root=root->left;
//             }
//             else{
//                 root=root->right;
//             }
//         }
//     }
//     public:
//     BSTIterator(TreeNode* root,bool right=false){
//         this->right=right;
//         push(root);
//     }
//     int next(){
//         int ans=st.top()->val;
//         TreeNode* root=st.top();
//         st.pop();
//         if(!right){
//             push(root->right);
//         }
//         else{
//             push(root->left);
//         }
//         return ans;
//     }
// };
// class Solution {
// public:
//     bool findTarget(TreeNode* root, int k) {
//         BSTIterator l(root);
//         BSTIterator r(root,1);
//         int nodel=l.next();
//         int noder=r.next();
//         while(nodel<noder){
//             int sum=nodel+noder;
//             if(sum==k)
//                 return true;
//             if(sum>k){
//                 noder=r.next();
//             }
//             else{
//                 nodel=l.next();
//             }
//         }
//         return false;
//     }
// };