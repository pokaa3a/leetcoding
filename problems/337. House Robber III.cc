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
    int helper(TreeNode* root, int &left, int &right){
        if(!root) return 0;
        
        int leftGrandL=0, leftGrandR=0, rightGrandL=0, rightGrandR=0;
        left = helper(root->left, leftGrandL, leftGrandR);
        right = helper(root->right, rightGrandL, rightGrandR);
        
        return max(root->val+leftGrandL+leftGrandR+rightGrandL+rightGrandR, left+right);
    }
    int rob(TreeNode* root) {
        if(!root) return 0;
        int left=0, right=0;
        return helper(root, left, right);
    }
};