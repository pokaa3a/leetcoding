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
// O(n*nlogn)
const int MOD = 1000000007;
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (n < k * m) return -1;
        
        int lo = *min_element(bloomDay.begin(), bloomDay.end());
        int hi = *max_element(bloomDay.begin(), bloomDay.end());
        
        while (lo < hi) {
            int mi = lo + (hi - lo) / 2;
            int bouquets = numBouquets(bloomDay, k, mi);
            if (bouquets >= m) {
                hi = mi;
            } else {
                lo = mi + 1;
            }
        }
        return lo;
    }
    
    int numBouquets(vector<int>& bloomDay, int k, int days) {
        int bouquets = 0;
        int flowers = 0;
        for (int x : bloomDay) {
            if (x <= days) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
        }
        return bouquets;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */


}