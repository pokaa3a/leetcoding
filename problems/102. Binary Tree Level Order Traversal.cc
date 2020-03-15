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
    void traversal(vector<vector<int>>& nums, TreeNode *p, int level) {
        if(!p) return;
        if(nums.size()<=level) nums.push_back(vector<int>());
        nums[level].push_back(p->val);
        traversal(nums, p->left, level+1);
        traversal(nums, p->right, level+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> nums;
        traversal(nums, root, 0);
        return nums;
    }
};