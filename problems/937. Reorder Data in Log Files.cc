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
	struct cmp {
		bool operator() (const string& a, const string& b) {
			if (a.substr(a.find(' ')) == b.substr(b.find(' '))) {
				return a.substr(0, a.find(' ') + 1) < b.substr(0, b.find(' '));
			}
			return a.substr(a.find(' ')) < b.substr(b.find(' '));
		}
	};
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
    	vector<string> ans, dig_logs;
    	for (int i = 0; i < logs.size(); ++i) {
    		if (is_let(logs[i])) ans.push_back(logs[i]);
    		else dig_logs.push_back(logs[i]);
    	}
    	sort(ans.begin(), ans.end(), cmp());
    	for (int i = 0; i < dig_logs.size(); ++i) {
    		ans.push_back(dig_logs[i]);
    	}
    	return ans;
    }
    bool is_let(string a) {
    	int dig = a.find(' ') + 1;
    	if (a[dig] >= '0' && a[dig] <= '9') return false;
    	return true;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	vector<string> logs;
	logs.push_back("a1 9 2 3 1");
	logs.push_back("g1 act car");
	logs.push_back("zo4 4 7");
	logs.push_back("ab1 off key dog");
	logs.push_back("a8 act zoo");

	vector<string> res = sol.reorderLogFiles(logs);
	for (int i = 0; i < res.size(); ++i) {
		cout << res[i] << endl;
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