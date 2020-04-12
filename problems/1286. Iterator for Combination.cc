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
class CombinationIterator {
public:
    vector<int> digits;
    vector<char> chars;
    int pivot;
    CombinationIterator(string characters, int combinationLength) {
        for (char c : characters) {
          chars.push_back(c);
        }
        digits.resize(combinationLength, 0);
        
        // initialize
        for (int i = 0; i < digits.size(); i++) {
          digits[i] = i;
        }
        digits.back()--;
        pivot = digits.size() - 1;
    }
    
    string next() {
        if (hasNext()) {
            int pivot = digits.size() - 1;
            while (digits[pivot] + 1 == chars.size() - (digits.size() - 1 - pivot)) {
                pivot--;
            }
            digits[pivot]++;
            for (int i = pivot + 1; i < digits.size(); i++) {
                digits[i] = digits[i - 1] + 1;
            }
        }
        
        string ans = "";
        for (int d : digits) {
          ans += chars[d];
        }

        return ans;
    }
    
    bool hasNext() {
        if (digits[0] == chars.size() - digits.size()) return false;
        else return true;
    }
};



int main() {
	/* Solution */
	Solution sol;

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