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
class Cashier {
	int count_, n_, discount_;
	unordered_map<int, int> prices_;
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        count_ = 0;
        n_ = n;
        discount_ = discount;
        for (int i = 0; i < products.size(); ++i) {
            prices_[products[i]] = prices[i];
        }
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        double cost = 0;
        for (int i = 0; i < product.size(); ++i) {
        	int id = product[i];
        	cost += double(prices_[id] * amount[i]);
        }
        if (++count_ == n_) {
        	cost = cost - ((double)discount_ * cost) / 100;
        	count_ = 0;
        }
        return cost;
    }
};



int main() {
	/* Solution */
	// Cashier cashier;

	/* Test cases */

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