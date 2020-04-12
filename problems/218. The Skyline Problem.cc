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
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        return getSkyline(buildings, 0, buildings.size() - 1);
    }
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings, int lo, int hi) {
    	int n = hi - lo + 1;
    	vector<vector<int>> output;
    	if (n == 0) return output;
    	if (n == 1) {
    		output.push_back(vector<int>{buildings[lo][0], buildings[lo][2]});
    		output.push_back(vector<int>{buildings[lo][1], 0});
            return output;
    	}
    	int mid = lo + (hi - lo) / 2;
    	vector<vector<int>> leftSkyLine = getSkyline(buildings, lo, mid);
    	vector<vector<int>> rightSkyLine = getSkyline(buildings, mid + 1, hi);
    	return mergeSkyLines(leftSkyLine, rightSkyLine);
    }

    vector<vector<int>> mergeSkyLines(vector<vector<int>>& leftSkyLine, 
    								  vector<vector<int>>& rightSkyLine) {
    	int nL = leftSkyLine.size(), nR = rightSkyLine.size();
    	int pL = 0, pR = 0;
    	int curY = 0, leftY = 0, rightY = 0;
    	int x, maxY;
    	vector<vector<int>> output;

    	while (pL < nL && pR < nR) {
    		vector<int> pointL = leftSkyLine[pL];
    		vector<int> pointR = rightSkyLine[pR];

    		if (pointL[0] < pointR[0]) {
    			x = pointL[0];
    			leftY = pointL[1];
    			pL++;
    		} else if (pointR[0] < pointL[0]) {
    			x = pointR[0];
    			rightY = pointR[1];
    			pR++;
    		} else {
                if (pointL[1] > pointR[1]) {
                    x = pointL[0];
                    leftY = pointL[1];
                    pL++;
                } else {
                    x = pointR[0];
                    rightY = pointR[1];
                    pR++;
                }
            }
    		maxY = max(leftY, rightY);
    		if (curY != maxY) {
    			updateOutput(output, x, maxY);
    			curY = maxY;
    		}
    	}
    	appendSkyline(output, leftSkyLine, pL, nL, curY);
    	appendSkyline(output, rightSkyLine, pR, nR, curY);
    	return output;
    }

    void updateOutput(vector<vector<int>>& output, int x, int y) {
    	if (output.size() == 0 || output.back()[0] != x) {
    		output.push_back(vector<int>{x, y});
    	} else {
    		output.back()[1] = y;
    	}
    }

    void appendSkyline(vector<vector<int>>& output, vector<vector<int>>& skyLine,
    				   int p, int n, int curY) {
    	while (p < n) {
    		vector<int> point = skyLine[p];
    		int x = point[0], y = point[1];
    		p++;
    		if (y != curY) {
    			updateOutput(output, x, y);
    			curY = y;
    		}
    	}
    }
};



int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	vector<vector<int>> buildings = {{1, 2, 1}, {1, 2, 3}};
	vector<vector<int>> skyline = sol.getSkyline(buildings);

	for (auto point : skyline) {
		cout << point[0] << ", " << point[1] << endl;
	}


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