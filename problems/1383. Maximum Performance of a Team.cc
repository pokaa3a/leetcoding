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
const int MOD = 1000000007;
class Solution {
	struct cmp {
		bool operator() (const pair<int, int>& a, const pair<int, int>& b) {
			return a.second > b.second || (a.second == b.second && a.first > b.first);
		}
	};
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
    	vector<pair<int, int> > ppl;
    	for (int i = 0; i < n; i++) {
    		ppl.push_back(make_pair(speed[i], efficiency[i]));
    	}
    	sort(ppl.begin(), ppl.end(), cmp());

    	priority_queue<int> pq;
    	long long speed_sum = 0, min_ef = 0, ans = 0;
    	for (int i = 0; i < n; ++i) {
    		min_ef = ppl[i].second;
    		speed_sum += (long long) ppl[i].first;
    		pq.push(-ppl[i].first);
    		while (pq.size() > k) {
    			speed_sum += pq.top();
    			pq.pop();
    		}
    		ans = max(ans, speed_sum * min_ef);
    	}
    	return int(ans % MOD);
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