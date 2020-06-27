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
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> freq;
        for (int x : arr) {
            freq[x]++;
        }
        vector<int> count;
        for (auto p : freq) {
            count.push_back(p.second);
        }
        sort(count.begin(), count.end());
        
        int i = 0;
        while (k > 0) {
            k -= count[i];
            if (k >= 0) i++;
        }
        return count.size() - i;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */


}