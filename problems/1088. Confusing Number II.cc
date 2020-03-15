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
	vector<long long> valid;
	map<long long, long long> rotate;
public:
    int confusingNumberII(int N) {
        int ans = 0;
        int v[] = {0, 1, 6, 8, 9};
        valid = vector<long long>(v, v + 5);

        rotate[0] = 0;
        rotate[1] = 1;
        rotate[6] = 9;
        rotate[8] = 8;
        rotate[9] = 6;

        for (int i = 1; i < valid.size(); ++i) {
        	backtrack(valid[i], rotate[valid[i]], 10, ans, N);
        }
        return ans;
    }
    void backtrack(long long v, long long v_r, long long digit, int& ans, int& N) {
    	// cout << "v: " << v << " v_r: " << v_r << endl;
    	if (v != v_r) ans++;
    	for (int i = 0; i < valid.size(); ++i) {
    		if (v * 10 + valid[i] > N) break;
    		else {
    			backtrack(v * (long long)10 + valid[i], rotate[valid[i]] * digit + v_r, digit * 10, ans, N);
    		}
    	}
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	int N = 100;
	cout << sol.confusingNumberII(N) << endl;

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