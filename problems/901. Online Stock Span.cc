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
class StockSpanner {
private:
    int n;  // number of days
    unordered_map<int, int> mp;
	stack<int> stk;
public:
    StockSpanner() {
        n = 1;
    }
    
    int next(int price) {
        mp[price] = n++;
        while (!stk.empty() && stk.top() <= price) {
        	stk.pop();
        }
        if (stk.empty()) {
        	stk.push(price);
        	return mp[price];
        }
        // cout << "stk top: " << stk.top() << endl;
        int con_days = mp[price] - mp[stk.top()];
        stk.push(price);
        
        return con_days;
    }
};



int main() {
	/* Solution */
	StockSpanner ss;

	cout << ss.next(100) << endl;
	cout << ss.next(80) << endl;
	cout << ss.next(60) << endl;
	cout << ss.next(70) << endl;

	/* Test cases */

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