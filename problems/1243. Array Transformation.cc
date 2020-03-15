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
    vector<int> transformArray(vector<int>& arr) {
        vector<int> arr_new = update(arr);
        while (!areEqual(arr, arr_new)) {
        	arr = arr_new;
        	arr_new = update(arr);
        }
        return arr_new;
    }
    vector<int> update(vector<int>& arr) {
    	vector<int> arr_new = arr;
    	for (int i = 1; i < arr.size() - 1; ++i) {
    		if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {
    			arr_new[i]++;
    		} else if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]){
    			arr_new[i]--;
    		}
    	}
    	return arr_new;
    }
    bool areEqual(vector<int>& a, vector<int>& b) {
    	bool res = 1;
    	for (int i = 0; i < a.size(); ++i) {
    		res &= a[i] == b[i];
    	}
    	return res;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	int a[] = {1,6,3,4,3,5};
	vector<int> arr(a, a + 6);

	vector<int> ans = sol.transformArray(arr);
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << " ";
	}

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