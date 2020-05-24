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
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        vector<pair<double, double>> workers;
        int n = quality.size();

        for (int i = 0; i < n; i++) {
        	workers.push_back(make_pair((double)wage[i] / (double)quality[i], quality[i]));
        }
        sort(workers.begin(), workers.end());

        priority_queue<double> pq;
        double res = 1e9;
        double sumq = 0;
        for (auto worker : workers) {
        	sumq += worker.second;

        	pq.push(worker.second);

        	if (pq.size() > K) {
        		double q = pq.top();
        		sumq -= q;
        		pq.pop();
        	}
        	if (pq.size() == K) {
        		res = min(res, sumq * worker.first);
        	}
        }
        return res;
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