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
class CustomStack {
	int max_size_;
	int cur_size_;
	vector<int> stk;
public:
    CustomStack(int maxSize) {
        max_size_ = maxSize;
        cur_size_ = 0;
        stk.resize(maxSize);
    }
    
    void push(int x) {
        if (cur_size_ == max_size_) return;
        stk[cur_size_++] = x;
    }
    
    int pop() {
        if (cur_size_ == 0) return -1;
        return stk[--cur_size_];
    }
    
    void increment(int k, int val) {
        for (int i = 0; i < min(cur_size_, k); i++) {
        	stk[i] += val;
        }
    }
};



int main() {
	/* Solution */
	CustomStack cs(3);
	cs.push(1);
	cs.push(2);
	cout << cs.pop() << endl;
	cs.push(2);
	cs.push(3);
	cs.push(4);
	cs.increment(5, 100);
	cs.increment(2, 100);
	cout << cs.pop() << endl;
	cout << cs.pop() << endl;
	cout << cs.pop() << endl;
	cout << cs.pop() << endl;


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