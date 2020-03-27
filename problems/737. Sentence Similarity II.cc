#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <queue>
#include <stack>
#include <sstream>
#include <cmath>
#include <numeric>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void traverse(TreeNode* root) {
	if (!root) return;
	cout << root->val << endl;
	traverse(root->left);
	traverse(root->right);
}

/* Solution */
const int MOD = 1000000007;
class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, 
    							vector<vector<string> >& pairs) {
        if (words1.size() != words2.size()) return false;

        unordered_map<string, int> dict;
        vector<int> group;
        for (int i = 0; i < pairs.size(); i++) {
        	string w1 = pairs[i][0], w2 = pairs[i][1];
        	if (dict.find(w1) == dict.end()) {
        		dict[w1] = dict.size();
        		group.push_back(dict[w1]);
        	}
        	if (dict.find(w2) == dict.end()) {
        		dict[w2] = dict.size();
        		group.push_back(dict[w2]);
        	}
        	uni(dict[w1], dict[w2], group);
        }

        for (int i = 0; i < words1.size(); i++) {
        	string w1 = words1[i], w2 = words2[i];
        	if (dict.find(w1) == dict.end()) {
        		if (w1 != w2) {
        			return false;
        		}
        	} else {
        		if (dict.find(w2) == dict.end()) return false;
        		int a = find(dict[w1], group);
        		int b = find(dict[w2], group);
        		if (a != b) {
        			return false;
        		}
        	}
        }
        return true;
    }
    int find(int x, vector<int>& group) {
    	if (x != group[x]) group[x] = find(group[x], group);
    	return group[x];
    }
    void uni(int x, int y, vector<int>& group) {
    	int a = find(x, group), b = find(y, group);
    	if (a != b) group[a] = b;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */

	/* [1-D vector] */
	// int arr[] = {};
	// vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));

	/* [2-D vector] */
	// const int rows = 1;
	// const int cols = 1;
	// int arr[rows][cols] = {{1}};
	// vector<vector<int> > grid;
	// for (int r = 0; r < rows; ++r) {
	// 	grid.push_back(vector<int>(arr[r], arr[r] + cols));
	// }

	/* [String] */
	// string str = "";

}