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

const int MOD = 1000000007;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* Solution */
class Solution {
public:
    vector<vector<int> > allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<tuple<int, int, int> > dist;
        for (int r = 0; r < R; r++) {
        	for (int c = 0; c < C; c++) {
        		int d = abs(r - r0) + abs(c - c0);
        		dist.push_back(make_tuple(d, r, c));
        	}
        }
        sort(dist.begin(), dist.end());
        vector<vector<int> > ans;
        for (int i = 0; i < dist.size(); ++i) {
        	int a[] = {get<1>(dist[i]), get<2>(dist[i])};
        	ans.push_back(vector<int>(a, a + 2));
        }
        return ans;
    }
};

int main() {
	// Solution
	Solution sol;

	// Test cases

}