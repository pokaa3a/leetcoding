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
    int minKnightMoves(int x, int y) {
        queue<pair<int, int> > q;
        map<pair<int, int>, int> dp;
        set<pair<int, int> > visited;

        int step = 0;
        q.push(make_pair(0, 0));
    	visited.insert(make_pair(0, 0));
    	while (!q.empty()) {
    		int q_size = q.size();
    		for (int i = 0; i < q_size; ++i) {
    			pair<int, int> p = q.front(); q.pop();
    			int r = p.first;
    			int c = p.second;
    			dp[make_pair(r, c)] = step;

    			if (dp.find(make_pair(x - r, y - c)) != dp.end()) {
    				return step + dp[make_pair(x - r, y - c)];
    			}
    			for (int xx = 2; xx >= -2; xx -= 4) {
    				for (int yy = 1; yy >= -1; yy -= 2) {
    					if (!visited.count(make_pair(r + xx, c + yy))) {
    						q.push(make_pair(r + xx, c + yy));
    						visited.insert(make_pair(r + xx, c + yy));
    					}
    				}
    			}
    			for (int xx = 1; xx >= -1; xx -= 2) {
    				for (int yy = 2; yy >= -2; yy -= 4) {
    					if (!visited.count(make_pair(r + xx, c + yy))) {
    						q.push(make_pair(r + xx, c + yy));
    						visited.insert(make_pair(r + xx, c + yy));
    					}
    				}
    			}
    		}
    		step++;
    	}
    	return step;
    }
};


int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	int x = 5, y = 5;
	cout << sol.minKnightMoves(x, y) << endl;

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