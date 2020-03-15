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

/* Solution */
const int MOD = 1000000007;
class Solution {
public:
    int maximumMinimumPath(vector<vector<int> >& A) {
        int rows = A.size(), cols = A[0].size();
        vector<pair<int, pair<int, int> > > cells;

        for (int i = 0; i < rows; ++i) {
        	for (int j = 0; j < cols; ++j) {
        		cells.push_back(make_pair(A[i][j], make_pair(i, j)));
        	}
        }
        sort(cells.begin(), cells.end(), greater<pair<int, pair<int, int> > >());

        vector<int> group(rows * cols, 0);
        for (int i = 0; i < group.size(); ++i) group[i] = i;

        set<pair<int, int> > added;
        for (int i = 0; i < cells.size(); ++i) {
        	int r = cells[i].second.first;
        	int c = cells[i].second.second;
        	// cout << "(" << r << ", " << c << "): " << cells[i].first << endl;

        	int x = find(r * cols + c, group);
        	if (added.count(make_pair(r - 1, c))) {
        		int y = find((r - 1) * cols + c, group);
        		if (x != y) group[y] = x;
        	}
        	if (added.count(make_pair(r + 1, c))) {
        		int y = find((r + 1) * cols + c, group);
        		if (x != y) group[y] = x;
        	}
        	if (added.count(make_pair(r, c - 1))) {
        		int y = find(r * cols + c - 1, group);
        		if (x != y) group[y] = x;
        	}
        	if (added.count(make_pair(r, c + 1))) {
        		int y = find(r * cols + c + 1, group);
        		if (x != y) group[y] = x;
        	}

        	if (find(0, group) == find((rows - 1) * cols + cols - 1, group)) 
        		return cells[i].first;
        	added.insert(make_pair(r, c));
        }
        return cells.back().first;
    }

    int find (int x, vector<int>& group) {
    	if (x != group[x]) group[x] = find(group[x], group);
    	return group[x];
    }
};
int main() {
	/* Solution */
	Solution sol;

	/* Test cases */

	/* [1-D vector] */
	// const int a = 1;
	// int arr[] = {};
	// vector<int> nums(arr, arr + a);

	/* [2-D vector] */
	const int rows = 6;
	const int cols = 5;
	int arr[rows][cols] = {{3,4,6,3,4}, {0,2,1,1,7}, {8,8,3,2,7}, {3,2,4,9,8}, 
						   {4,1,2,0,0}, {4,6,5,4,3}};
	vector<vector<int> > grid;
	for (int r = 0; r < rows; ++r) {
		grid.push_back(vector<int>(arr[r], arr[r] + cols));
	}
	cout << sol.maximumMinimumPath(grid) << endl;

	/* [String] */
	// string str = "";

}