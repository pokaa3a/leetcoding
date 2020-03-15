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
// class Solution {
// public:
//     int minDeletionSize(vector<string>& A) {
//         int n = A[0].size();
// 		vector<string> seq(A.size(), "");

// 		for (int i = 0; i < n; ++i) {
// 			vector<string> tmp = seq;
// 			tmp[0] += A[0][i];
// 			bool a = true, b = true, c = true;
// 			for (int k = 1; k < A.size(); ++k) {
// 				tmp[k] += A[k][i];
// 				a &= tmp[k - 1] < tmp[k];
// 				b &= tmp[k - 1] <= tmp[k];
// 			}
// 			if (a) return i - seq[0].size();
// 			if (b) seq = tmp;
// 		}
        
// 		return n - seq[0].size();
//     }
// };

class Solution {
public:
	int minDeletionSize(vector<string>& A) {
		int n = A[0].size();
		vector<bool> sorted(A.size() - 1, false);
		int deletions = 0;

		for (int i = 0; i < n; ++i) {
			int k;
			for (k = 0; k < A.size() - 1; ++k) {
				if (!sorted[k] && A[k][i] > A[k + 1][i]) {
					deletions++;
					break;
				}
			}
			if (k == A.size() - 1) {
				for (int j = 0; j < A.size() - 1; ++j) {
					sorted[j] = sorted[j] || A[j][i] < A[j + 1][i];
				}
			}
		}
		return deletions;
	}
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	vector<string> A;
	A.push_back("cacb");
	A.push_back("babb");
	A.push_back("abaa");

	cout << sol.minDeletionSize(A) << endl;

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