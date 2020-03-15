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
    int maxEvents(vector<vector<int> >& events) {
    	priority_queue<int, vector<int>, greater<int> > pq;
    	sort(events.begin(), events.end());

    	int n = events.size(), i = 0, day = 1, ans = 0;
    	while (!pq.empty() || i < n) {
    		if (pq.empty()) {
    			day = events[i][0];
    		}
    		while (i < n && events[i][0] == day) {
    			pq.push(events[i][1]);
     			i++;
    		}
    		ans++;
    		day++;
    		pq.pop();
    		while (!pq.empty() && pq.top() < day) {
    			pq.pop();
    		}
    	}
    	return ans;
    }
};


int main() {
	/* Solution */
	Solution sol;

	/* Test cases */

	/* [1-D vector] */
	// const int a = 1;
	// int arr[] = {};
	// vector<int> nums(arr, arr + a);

	/* [2-D vector] */
	const int rows = 4;
	const int cols = 2;
	int arr[rows][cols] = {{1,2}, {2,3}, {3,4}, {1,2}};
	vector<vector<int> > grid;
	for (int r = 0; r < rows; ++r) {
		grid.push_back(vector<int>(arr[r], arr[r] + cols));
	}

	cout << sol.maxEvents(grid) << endl;
	/* [String] */
	// string str = "";

}