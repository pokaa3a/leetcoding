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
class MyCalendar {
	map<int, int> ends;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
    	map<int, int>::iterator it = ends.upper_bound(start);
    	if (it != ends.end()) {
    		if (it->second < end) return false;
    	}
    	// if (ends.find(end) == ends.end()) ends[end] = start;
    	ends[end] = max(ends[end], start);
    	return true;
    }
};



int main() {
	/* Solution */

	/* Test cases */
	MyCalendar mc;
	cout << mc.book(10, 20) << endl;
	cout << mc.book(15, 25) << endl;
	// cout << mc.book(20, 30) << endl;
	cout << mc.book(20, 21) << endl;

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