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
        if (root == NULL) return "#";
        return to_string(root->val) + " " + serialize(root->left) + " " + serialize(root->right);
    }

    TreeNode* deserialize(string data) {
        if(data=="#") return NULL;
        stringstream str(data);
        return myDeserialize(str);
    }
    
    TreeNode* myDeserialize(stringstream &str){
        string s;
        str>>s;
        if(s=="#") return NULL;
        TreeNode* node = new TreeNode(stoi(s));
        node->left = myDeserialize(str);
        node->right = myDeserialize(str);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));