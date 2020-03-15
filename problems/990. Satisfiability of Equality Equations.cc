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
    bool equationsPossible(vector<string>& equations) {
		group.resize(26, 0);
		for (int i = 0; i < 26; i++) group[i] = i;

		for (int i = 0; i < equations.size(); ++i) {
			if (equations[i][1] == '!') continue;
			int x = equations[i][0] - 'a';
			int y = equations[i][3] - 'a';
			int g_x = find(x);
			int g_y = find(y);
			group[g_x] = g_y;
		}
		for (int i = 0; i < equations.size(); ++i) {
			if (equations[i][1] == '=') continue;
			int x = equations[i][0] - 'a';
			int y = equations[i][3] - 'a';
			int g_x = find(x);
			int g_y = find(y);
			// cout << x << ", " << y << endl;
			// cout << g_x << ", " << g_y << endl;
			if (x == y) return false;
			if (g_x == g_y) return false;
		}
		return true;
    }
private:
	vector<int> group;
	int find(int x) {
		if (x != group[x]) group[x] = find(group[x]);
		return group[x];
	}
};

int main() {
	// Solution
	Solution sol;

	// Test cases
	vector<string> equations;
	equations.push_back("c==c");
	equations.push_back("b==d");
	equations.push_back("x!=z");
	// equations.push_back("b==c");
	cout << sol.equationsPossible(equations) << endl;

}