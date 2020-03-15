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

/* Solution */
const int MOD = 1000000007;
class Solution {
public:
    vector<vector<string> > findLadders(string beginWord, string endWord, vector<string>& wordList) {
    	queue<vector<string> > q;
    	vector<vector<string> > ans;
    	unordered_set<string> dict(wordList.begin(), wordList.end());
    	dict.insert(beginWord);
    	q.push(vector<string>(1, beginWord));

    	while (!q.empty()) {
    		int q_size = q.size();
    		unordered_set<string> reachables;
    		bool reach_end = false;
    		for (int i = 0; i < q_size; ++i) {
    			vector<string> path = q.front();
    			q.pop();
    			if (path.back() == endWord) {
    				ans.push_back(path);
    				reach_end = true;
    			} else {
    				string cur_word = path.back();
    				for (int j = 0; j < cur_word.size(); ++j) {
    					string tmp = cur_word;
    					for (char c = 'a'; c <= 'z'; ++c) {
    						tmp[j] = c;
    						if (tmp == cur_word) continue;
    						if (dict.count(tmp) > 0) {
    							reachables.insert(tmp);
    							q.push(path);
    							q.back().push_back(tmp);
    						}
    					}
    				}
    			}
    		}
    		if (reach_end) break;
    		for (unordered_set<string>::iterator it = reachables.begin(); it != reachables.end(); ++it) {
    			dict.erase(*it);
    		}
    	}
    	return ans;
    }
};


void traverse(TreeNode* root) {
	if (!root) return;
	cout << root->val << endl;
	traverse(root->left);
	traverse(root->right);
}

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	string beginWord = "hit";
	string endWord = "cog";

	string w[] = {"hot","dot","dog","lot","log","cog"};
	vector<string> wordList(w, w + 6);

	vector<vector<string> > ans = sol.findLadders(beginWord, endWord, wordList);
	for (int i = 0; i < ans.size(); ++i) {
		for (int j = 0; j < ans[i].size(); ++j) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}

	/* [1-D vector] */
	// const int a = 1;
	// int arr[] = {};
	// vector<int> nums(arr, arr + a);

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