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
    vector<int> gardenNoAdj(int N, vector<vector<int> >& paths) {
        vector<vector<int> > graph(N, vector<int>());
        for (int i = 0; i < paths.size(); ++i) {
        	int p1 = paths[i][0] - 1;
        	int p2 = paths[i][1] - 1;
        	graph[p1].push_back(p2);
        	graph[p2].push_back(p1);
        }

        vector<int> ans(N, 0);
        for (int i = 0; i < N; ++i) {
        	plant(i, graph, ans);
        }
        return ans;
    }
    void plant(int i, vector<vector<int> >& graph, vector<int>& ans) {
    	vector<int> flowers(4, 0);
    	for (int j = 0; j < graph[i].size(); ++j) {
    		if (ans[graph[i][j]] != 0) {
    			// cout << "node: " << graph[i][j] << " is colored" << endl;
    			flowers[ans[graph[i][j]] - 1]++;
    		}
    	}
    	for (int k = 0; k < 4; ++k) {
    		if (flowers[k] == 0) {
    			ans[i] = k + 1;
    			return;
    		}
    	}
    }
};

int main() {
	// Solution
	Solution sol;

	// Test cases
	int N = 4;
	int p[2][2] = {{1,2}, {3,4}};
	vector<vector<int> > paths;
	paths.push_back(vector<int>(p[0], p[0] + 2));
	paths.push_back(vector<int>(p[1], p[1] + 2));
	// paths.push_back(vector<int>(p[2], p[2] + 2));
	vector<int> res = sol.gardenNoAdj(N, paths);
	for (int i = 0; i < res.size(); ++i) cout << res[i] << " ";
	cout << endl;
}