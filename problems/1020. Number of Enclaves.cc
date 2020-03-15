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
	int rows;
	int cols;
public:
    int numEnclaves(vector<vector<int> >& A) {
    	rows = A.size(); 
    	cols = A[0].size();

    	// top
    	for (int i = 0; i < cols; ++i) {
    		if (A[0][i] == 1) dfs(0, i, A);
    	}
    	// left
    	for (int i = 0; i < rows; ++i) {
    		if (A[i][0] == 1) dfs(i, 0, A);
    	}
    	// bot
    	for (int i = 0; i < cols; ++i) {
    		if (A[rows - 1][i] == 1) dfs(rows - 1, i, A);
    	}
    	// right
    	for (int i = 0; i < rows; ++i){
    		if (A[i][cols - 1]) dfs(i, cols - 1, A);
    	} 
    	
    	int ans = 0;
    	for (int i = 0; i < rows; ++i) {
    		for (int j = 0; j < cols; ++j) {
    			ans += A[i][j] == 1 ? 1 : 0;
    		}
    	}
    	return ans;
    }
    void dfs(int r, int c, vector<vector<int> >& A) {
    	A[r][c]++;
    	// top
    	if (r - 1 >= 0 && A[r - 1][c] == 1) dfs(r - 1, c, A);
    	// left
    	if (c - 1 >= 0 && A[r][c - 1] == 1) dfs(r, c - 1, A);
    	// bot
    	if (r + 1 < rows && A[r + 1][c] == 1) dfs(r + 1, c, A);
    	// right
    	if (c + 1 < cols && A[r][c + 1] == 1) dfs(r, c + 1, A);
    }
};

int main() {
	// Solution
	Solution sol;

	// Test cases
	int a[4][4] = {{0,0,0,0}, {1,0,1,0}, {0,1,1,0}, {0,0,0,0}};
	vector<vector<int> > A;
	for (int i = 0; i < 4; ++i) {
		A.push_back(vector<int>(a[i], a[i] + 4));
	}
	cout << sol.numEnclaves(A) << endl;
}