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
// O(n*k^2)
// n: number of words
// k: lengt of longest word
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> mp;
        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            mp[string(word.rbegin(), word.rend())] = i;
        }
        
        vector<vector<int>> output;
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                string l = words[i].substr(0, j), r = words[i].substr(j);
                if (mp.count(l) && isPalin(r) && mp[l] != i) output.push_back({i, mp[l]});
                if (mp.count(r) && isPalin(l) && mp[r] != i) output.push_back({mp[r], i});
            }
        }
        // handle ""
        if (mp.count("")) {
            for (int i = 0; i < words.size(); i++) {
                if (isPalin(words[i]) && words[i] != "") {
                    output.push_back({mp[""], i});
                }
            }
        }
        
        return output;
    }
    bool isPalin(string s) {
        for (int i = 0; i < s.size() / 2; i++) {
            if (s[i] != s[s.size() - 1 - i]) return false;
        }
        return true;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	vector<string> words = {"a", ""};
	sol.palindromePairs(words);

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