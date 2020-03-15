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
	int gcd(int a, int b) {
		if (a == 0) return b;
		return gcd(b % a, a);
	}
    int maxPoints(vector<vector<int> >& points) {
        int n = points.size();
        if (n <= 2) return n;

        int max_pts = 2;
        for (int i = 0; i < n - 1; i++) {
        	int i_x = points[i][0], i_y = points[i][1];
        	int max_pts_i = 1; // max number of points on a line passing through point-i
        	int same_pts = 0;
        	map<pair<int, int>, int> hash;
        	for (int j = i + 1; j < n; j++) {
        		int j_x = points[j][0], j_y = points[j][1];
        		if (i_x == j_x && i_y == j_y) {
        			same_pts++;
        			continue;
        		}
        		pair<int, int> slope(j_x - i_x, j_y - i_y);
        		slope.first = slope.second == 0 ? 1 : slope.first;
        		slope.second = slope.first == 0 ? 1 : slope.second;
        		if (slope.first != 0 && slope.second != 0) {
        			int g = gcd(slope.first, slope.second);
        			slope.first /= g;
        			slope.second /= g;
        		}
        		if (hash.find(slope) == hash.end()) hash[slope] = 1;
        		hash[slope]++;
        		max_pts_i = max(hash[slope], max_pts_i);
        	}
        	max_pts = max(max_pts_i + same_pts, max_pts);
        }
        return max_pts;
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
	const int rows = 4;
	const int cols = 2;
	int arr[rows][cols] = {{3,10}, {0,2}, {0,2}, {3,10}};
	vector<vector<int> > grid;
	for (int r = 0; r < rows; ++r) {
		grid.push_back(vector<int>(arr[r], arr[r] + cols));
	}
	cout << sol.maxPoints(grid) << endl;

	/* [String] */
	// string str = "";

}