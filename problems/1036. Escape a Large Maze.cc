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
private:
	int n;
	set<pair<int, int> > blocks;
public:
    bool isEscapePossible(vector<vector<int> >& blocked, vector<int>& source, vector<int>& target) {
        n = 1000000;
        for (int i = 0; i < blocked.size(); ++i) {
        	blocks.insert(make_pair(blocked[i][0], blocked[i][1]));
        }
        set<pair<int, int> > visited_0, visited_1;
        return dfs(source[0], source[1], target[0], target[1], visited_0) && dfs(target[0], target[1], source[0], source[1], visited_1);
    }
    bool dfs(int r, int c, int d_r, int d_c, set<pair<int, int> >& visited) {
    	if (r < 0 || r >= n || c < 0 || c >= n || blocks.count(make_pair(r, c)) > 0 || visited.count(make_pair(r, c)) > 0) {
    		return false;
    	}
    	visited.insert(make_pair(r, c));
    	if (visited.size() > 20000 || (r == d_r && c == d_c)) return true;
    	return dfs(r - 1, c, d_r, d_c, visited) || dfs(r, c - 1, d_r, d_c, visited) || 
    		   dfs(r + 1, c, d_r, d_c, visited) || dfs(r, c + 1, d_r, d_c, visited);
    }
};

int main() {
	// Solution
	Solution sol;

	// Test cases
	int b[4][2] = {{10, 9}, {9, 10}, {10, 11}, {11, 10}};
	int s[] = {0, 0};
	int t[] = {10, 10};
	vector<vector<int> > blocked;
	blocked.push_back(vector<int>(b[0], b[0] + 2));
	blocked.push_back(vector<int>(b[1], b[1] + 2));
	blocked.push_back(vector<int>(b[2], b[2] + 2));
	blocked.push_back(vector<int>(b[3], b[3] + 2));
	vector<int> source(s, s + 2);
	vector<int> target(t, t + 2);
	cout << sol.isEscapePossible(blocked, source, target) << endl;
}