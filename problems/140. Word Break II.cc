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
	unordered_set<string> dict;
	int max_len;
    unordered_map<string, vector<string>> record;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        max_len = 0;
        for (string word : wordDict) {
        	dict.insert(word);
        	max_len = max(max_len, (int)word.size());
        }
        return helper(s);
    }
    vector<string> helper(string s) {
        if (record.find(s) != record.end()) return record[s];
        
    	vector<string> output;
    	if (s.size() == 0) {
    		output.push_back("");
    		return output;
    	}

    	for (int i = 0; i < min((int)s.size(), max_len); i++) {
    		string word = s.substr(0, i + 1);
    		if (dict.count(word) > 0) {
    			vector<string> next = helper(s.substr(i + 1));
    			for (int j = 0; j < next.size(); j++) {
    				if (next[j] == "") {
    					output.push_back(word);
    				} else {
    					output.push_back(word + " " + next[j]);
    				}
    			}
    		}
    	}
        record[s] = output;
    	return output;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	string s = "catsandog";
	vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"};

	vector<string> res = sol.wordBreak(s, wordDict);
	for (string s : res) cout << s << endl;

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