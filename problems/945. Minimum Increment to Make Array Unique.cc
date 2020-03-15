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
    int minIncrementForUnique(vector<int>& A) {
    	if (!A.size()) return 0;

        map<int, int> count;
        for (int i = 0; i < A.size(); ++i) count[A[i]]++;

        int ans = 0;
        int pre = -1;
        for (map<int, int>::iterator it = count.begin(); it != count.end(); ++it) {
        	// for (int i = 0; i < it->second; ++i) {
        	// 	if (it->first <= pre) {
        	// 		ans += pre - it->first + 1;
        	// 		pre++;
        	// 	} else {
        	// 		pre = it->first;
        	// 	}
        	// }
        	if (it->first <= pre) {
        		ans += (((pre - it->first + 1) + (pre - it->first + it->second)) * it->second) / 2;
        		pre += it->second;
        	} else {
        		ans += (it->second - 1) * it->second / 2;
        		pre = it->first + (it->second - 1);
        	}
        }
        return ans;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	int a[] = {1,2,2};
	vector<int> A(a, a + 3);

	cout << sol.minIncrementForUnique(A) << endl;

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