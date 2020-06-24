#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <queue>
#include <stack>
#include <list>
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
// class Solution {
// public:
//     vector<int> getStrongest(vector<int>& arr, int k) {
//         int n = arr.size();
//         sort(arr.begin(), arr.end());
//         int med = arr[(n - 1) / 2];

//         sort(arr.begin(), arr.end(), [&](int a, int b) -> bool {
//         	return abs(a - med) > abs(b - med) ||
//         		   (abs(a - med) == abs(b - med) && a > b);
//         });
//         return vector<int> (arr.begin(), arr.begin() + k);
//     }
// };

class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int med = arr[(n - 1) / 2];

        int lo = 0, hi = n - 1;
        vector<int> res;
        for (int i = 0; i < k; i++) {
        	if (abs(arr[lo] - med) > abs(arr[hi] - med)) {
        		res.push_back(arr[lo++]);
        	} else {
        		res.push_back(arr[hi--]);
        	}
        }
        return res;
    }
};

int main() {
	/* Solution */
	Solution sol;

	vector<int> arr = {6,7,11,7,6,8};
	int k = 5;
	vector<int> res = sol.getStrongest(arr, k);
	for (auto x : res) cout << x << " ";
}