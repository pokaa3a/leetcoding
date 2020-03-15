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
	int findLongest(TreeNode* root, int longest, int current){
		if(!root){
			return longest;
		}

		int longest_left = 1, longest_right = 1;

		if(root->left){
			if(root->left->val == root->val+1){
				longest_left = findLongest(root->left, max(longest, current+1), current+1);
			}
			else{
				longest_left = findLongest(root->left, longest, 1);
			}
		}
		else{
			longest_left = longest;
		}

		if(root->right){
			if(root->right->val == root->val+1){
				longest_right = findLongest(root->right, max(longest, current+1), current+1);
			}
			else{
				longest_right = findLongest(root->right, longest, 1);
			}
		}
		else{
			longest_right = longest;
		}

		return max(longest_left, longest_right);
	}

	int longestConsecutive(TreeNode* root) {
        if(!root) return 0;
		return findLongest(root, 1, 1);
	}
};