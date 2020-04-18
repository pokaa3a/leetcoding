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
private:
	struct TrieNode {
		vector<TrieNode*> next;
		bool isEnd;
		TrieNode() : next(26), isEnd(false) {}
	};
	TrieNode* root;

	void add(string s) {
		TrieNode* p = root;
		for (char c : s) {
			if (!p->next[c - 'a']) {
				p->next[c - 'a'] = new TrieNode();
			}
			p = p->next[c - 'a'];
		}
		p->isEnd = true;
	}
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        for (string word : words) {
        	add(word);
        }

        unordered_set<string> output;
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> used(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
        	for (int j = 0; j < n; j++) {
        		char c = board[i][j];
        		if (root->next[c - 'a']) {
	        		dfs(root->next[c - 'a'], "", i, j, board, used, output);
        		}
        	}
        }
        vector<string> res;
        for (string s : output) {
        	res.push_back(s);
        }
        return res;
    }
    void dfs(TrieNode* p, string word, int i, int j, vector<vector<char>>& board, 
    	     vector<vector<bool>>& used, unordered_set<string>& output) {
    	used[i][j] = true;
  		word += board[i][j];
    	if (p->isEnd) {
    		output.insert(word);
    	}
    	int m = board.size(), n = board[0].size();

    	int dirs[] = {-1, 0, 1, 0, -1};
    	for (int k = 0; k < 4; k++) {
    		if (i + dirs[k] >= 0 && i + dirs[k] < m &&
    			j + dirs[k + 1] >= 0 && j + dirs[k + 1] < n &&
    			!used[i + dirs[k]][j + dirs[k + 1]]) {
    			char c = board[i + dirs[k]][j + dirs[k + 1]];
    			if (p->next[c - 'a']) {
    				dfs(p->next[c - 'a'], word, i + dirs[k], j + dirs[k + 1], board, used, output);
    			}
    		}
    	}
    	used[i][j] = false;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	vector<vector<char>> board = {{'o', 'a', 'a', 'n'},
								  {'e', 't', 'a', 'e'},
								  {'i', 'h', 'k', 'r'},
								  {'i', 'f', 'l', 'v'}};
	vector<string> words = {"oath", "pea", "eat", "rain", "anea"};

	vector<string> res = sol.findWords(board, words);
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