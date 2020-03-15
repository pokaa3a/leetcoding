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
    void inorder(TreeNode* root, int k, int &path, int &val){
        if(!root) return;
        inorder(root->left, k, path, val);
        if(++path==k){
            val = root->val;
            return;
        } 
        inorder(root->right,k,path,val);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int path=0, val=0;
        inorder(root, k, path, val);
        return val;
    }
};