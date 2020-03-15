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
    int largestComponentSize(vector<int>& A) {
    	vector<int> group(A.size(), 0);
    	for (int i = 0; i < A.size(); ++i) group[i] = i;

    	map<int, int> pf_to_idx;
    	for (int i = 0; i < A.size(); ++i) {
    		int a = A[i];
    		if (a < 2) continue;

    		set<int> pf;
    		prime_factors(a, pf);
    		
    		for (set<int>::iterator it = pf.begin(); it != pf.end(); ++it) {
    			int p = *it;
    			if (pf_to_idx.find(p) == pf_to_idx.end()) {
    				pf_to_idx[p] = i;
    			}
    			uni(pf_to_idx[p], i, group);
    		}
    	}

    	map<int, int> count;
    	int ans = 0;
    	for (int i = 0; i < A.size(); ++i) {
    		int g = find(i, group);
    		count[g]++;
    		ans = max(ans, count[g]);
    	}

    	return ans;
    }

	int find(int x, vector<int>& group) {
		if (x != group[x]) group[x] = find(group[x], group);
		return group[x];
	}
	void uni(int x, int y, vector<int>& group) {
		int a = find(x, group);
		int b = find(y, group);
		if (a != b) group[a] = b;
	}
	void prime_factors(int x, set<int>& pf) {
		if (x < 2) return ;

		while (x % 2 == 0) {
			pf.insert(2);
			x /= 2;
		}
		for (int i = 3; i <= sqrt(x); i += 2) {
			while (x % i == 0) {
				pf.insert(i);
				x /= i;
			}
		}
		if (x > 2) pf.insert(x);
	}
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	int a[] = {20,50,9,63};
	vector<int> A(a, a + 4);

	cout << sol.largestComponentSize(A) << endl;

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