/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)
            return "";
        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node == nullptr)
                s += "#,";
            else{
                s += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (!data.size())
            return nullptr;
        // get first input from stream with delimiter and save to data
        stringstream stream(data);
        getline(stream, data, ',');
        // initialize tree root with string to integer conversion of data
        TreeNode* root = new TreeNode(stoi(data));
        queue<TreeNode*>q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();
            // get the next two inputs from stream as left and right
            string left, right;
            getline(stream, left, ',');
            getline(stream, right, ',');
            if (left == "#") 
                front->left = NULL;
            else {
                front->left = new TreeNode(stoi(left));
                q.push(front->left);
            }
            if (right == "#") 
                front->right = NULL;
            else {
                front->right = new TreeNode(stoi(right));
                q.push(front->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));