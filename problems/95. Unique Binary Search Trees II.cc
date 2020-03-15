#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<TreeNode*> generateTrees(int n) {
        if (n<1) {
            return vector<TreeNode*>();
        }
		return makeTrees(1,n);
	}

	vector<TreeNode*> makeTrees(int start, int end) {
		vector<TreeNode*> res;
		if(start > end) {
            res.push_back(NULL);
			return res;
		}

		if(start == end) {
			TreeNode *root = new TreeNode(start);
			res.push_back(root);
			return res;
		}

		for(int i = start; i <= end; ++i) {
			vector<TreeNode*> left_trees  = makeTrees(start, i-1);
			vector<TreeNode*> right_trees = makeTrees(i+1, end);
			for(int x=0; x < left_trees.size(); ++x) {
				TreeNode* left_tree = left_trees[x];
				for(int y=0; y < right_trees.size(); ++y) {
					TreeNode* right_tree = right_trees[y];
					TreeNode *root = new TreeNode(i);
					root->left  = left_tree;
					root->right = right_tree;
					res.push_back(root);
				}
			}
		}
		return res;
	}
};

void BFS(TreeNode* root) {
	if(root){
		cout << root->val << " ";
		BFS(root->left);
		BFS(root->right);
	} else {
		cout << "null ";
	}
}

int main(){
	Solution sol;
	vector<TreeNode*> res = sol.generateTrees(3);

	for(int i=0; i<res.size(); i++) {
		TreeNode* root = res[i];
		BFS(root);
		cout << endl;
	}
}