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
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> x_list(1, x);

        if (x > 1) {
	        for (int i = 0; pow(x, i) < bound; ++i) {
	        	x_list.push_back(pow(x, i));
	        }        	
        }

        vector<int> y_list(1, y);
        if (y > 1) {
			for (int i = 0; pow(y, i) < bound; ++i) {
	        	y_list.push_back(pow(y, i));
	        }        	
        }
        vector<int> ans;
        set<int> added;
        for (int i = 0; i < x_list.size(); ++i) {
        	for (int j = 0; j < y_list.size(); ++j) {
        		if (x_list[i] + y_list[j] <= bound &&
        			added.count(x_list[i] + y_list[j]) == 0) {
        			ans.push_back(x_list[i] + y_list[j]);
        			added.insert(x_list[i] + y_list[j]);
        		}
        	}
        }
        return ans;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	int x = 2, y = 1, bound = 10;
	vector<int> ans = sol.powerfulIntegers(x, y, bound);
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << " ";
	} 
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