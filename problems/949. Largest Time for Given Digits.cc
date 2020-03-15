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
    string largestTimeFromDigits(vector<int>& A) {
    	vector<int> used(4, 0);
    	vector<int> times;
    	dfs(0, A, used, times);
    	sort(times.begin(), times.end(), greater<int>());

    	for (int i = 0; i < times.size(); ++i) {
    		if (times[i] / 100 < 24 && times[i] % 100 < 60) {
    			return num_to_time(times[i]);
    		}
    	}
    	return "";
    }
    string num_to_time(int t) {
    	return to_string(t / 1000) + to_string((t % 1000) / 100) + ":" + to_string((t % 100) / 10) + to_string(t % 10);
    }

    void dfs(int num, vector<int>& A, vector<int>& used, vector<int>& times) {
    	for (int i = 0; i < A.size(); ++i) {
    		if (used[i]) continue;
    		used[i] = 1;
    		if (accumulate(used.begin(), used.end(), 0) == 4) times.push_back(num * 10 + A[i]);
    		else dfs(num * 10 + A[i], A, used, times);
    		used[i] = 0;
    	}
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	int a[] = {1,9,6,0};
	vector<int> A(a, a + 4);
	cout << sol.largestTimeFromDigits(A) << endl;

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