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
class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        map<int, int> m;
        for (int i = 0; i < A.size(); ++i) {
        	m[A[i]]++;
        }

        for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {
        	int x = it->first;
        	if (m[x]) {
	        	if (x < 0) {
	        		if (x % 2 == 1 || m[x] > m[x / 2]) return false;
	        		m[x / 2] -= m[x];
	        	} else {
	        		if (m[x] > m[x * 2]) return false;
	        		m[x * 2] -= m[x];
	        	}
        	}
        }
        return true;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	int a[] = {4,-2,2,-4};
	vector<int> A(a, a + 4);
	cout << sol.canReorderDoubled(A) << endl;

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