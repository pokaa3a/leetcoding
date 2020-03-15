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
class ProductOfNumbers {
	vector<int> prod;
	int zero;
public:
    ProductOfNumbers() {
        prod.resize(1, 1);
        zero = -1;
    }
    
    void add(int num) {
    	if (num > 0) prod.push_back(prod.back() * num);
    	else {
    		zero = prod.size();
    		prod.push_back(1);
    	}
    }
    
    int getProduct(int k) {
    	int n = prod.size();
    	if (n - k <= zero) return 0;

        return prod.back() / prod[n - k - 1];
    }
};



int main() {
	/* Solution */
	ProductOfNumbers pon;

	/* Test cases */
	pon.add(3);
	pon.add(0);
	pon.add(2);
	pon.add(5);
	pon.add(4);
	cout << pon.getProduct(2) << endl;
	cout << pon.getProduct(3) << endl;
	cout << pon.getProduct(4) << endl;
	pon.add(8);
	cout << pon.getProduct(2) << endl;

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