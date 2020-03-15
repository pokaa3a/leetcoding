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
    bool isLongPressedName(string name, string typed) {
        queue<pair<char, int> > n_q, t_q;
        summarize(name, n_q);
        summarize(typed, t_q);
        if (n_q.size() != t_q.size()) return false;
        while (!t_q.empty()) {
        	// cout << "name: (" << n_q.front().first << ", " << n_q.front().second << ")" << endl;
        	// cout << "typed: (" << t_q.front().first << ", " << t_q.front().second << ")" << endl;
        	if (t_q.front().first != n_q.front().first ||
        		t_q.front().second < n_q.front().second) return false;
        	t_q.pop();
        	n_q.pop();
        }
    	return true;
    }
    void summarize(string s, queue<pair<char, int> >& q) {
    	int i = 0;
    	while (i < s.size()) {
    		char c = s[i];
    		int cnt = 0;
    		while (s[i] == c) {
    			i++;
    			cnt++;
    		}
    		q.push(make_pair(c, cnt));
    	}
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	string name = "laiden";
	string typed = "laiden";
	cout << sol.isLongPressedName(name, typed) << endl;

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