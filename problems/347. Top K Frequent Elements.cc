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
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int x : nums) {
            freq[x]++;
        }
        vector<pair<int, int>> pairs;
        for (auto p : freq) {
            pairs.push_back(make_pair(p.second, p.first));  // freq, num
        }
        
        // quick select
        quickSelect(pairs, 0, pairs.size() - 1, k);
        vector<int> output;
        for (int i = 0; i < k; i++) {
            output.push_back(pairs[i].second);
        }
        return output;
    }
    void quickSelect(vector<pair<int, int>>& pairs, int lo, int hi, int k) {
        if (lo < hi) {
            int pivot = pairs[hi].first;
            int i = lo - 1;
            for (int j = lo; j < hi; j++) {
                if (pairs[j].first >= pivot) {
                    pair<int, int> tmp = pairs[++i];
                    pairs[i] = pairs[j];
                    pairs[j] = tmp;
                }
            }
            pair<int, int> tmp = pairs[i + 1];
            pairs[i + 1] = pairs[hi];
            pairs[hi] = tmp;
            
            int partition = i + 1;
            int left = partition - 1 - lo + 1;
            
            if (k <= left) {
                quickSelect(pairs, lo, partition - 1, k);
            } else if (k == left + 1) {
                return;
            } else {
                quickSelect(pairs, partition + 1, hi, k - (left + 1));
            }
        }
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	vector<int> nums = {5,3,1,1,1,3,5,73,1};
	int k = 3;
	vector<int> res = sol.topKFrequent(nums, k);
	for (int x : res) cout << x << " ";
	cout << endl;

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