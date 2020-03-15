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
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        deque<int> dq;
        int n = deck.size();
        for (int i = 0; i < n; ++i) {
        	dq.push_back(i);
        }
        vector<int> order;
        while (!dq.empty()) {
        	order.push_back(dq.front());
        	dq.pop_front();
        	dq.push_back(dq.front());
        	dq.pop_front();
        }
        vector<int> ans(n, 0);
        sort(deck.begin(), deck.end());

        for (int i = 0; i < n; ++i) {
        	ans[order[i]] = deck[i];
        }
        return ans;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	int a[] = {17,13,11,2,3,5,7};
	vector<int> A(a, a + 7);

	vector<int> res = sol.deckRevealedIncreasing(A);
	for (int i = 0; i < res.size(); ++i) cout << res[i] << " ";
	cout << endl;

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