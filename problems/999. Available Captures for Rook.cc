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
    int numRookCaptures(vector<vector<char>>& board) {
        int n = 8;
        int R_r, R_c;
        for (int i = 0; i < n; ++i) {
        	for (int j = 0; j < n; ++j) {
        		if (board[i][j] == 'R') {
        			R_r = i;
        			R_c = j;
        		}
        	}
        }

        int ans = 0;
        int r, c;
        // top
        r = R_r - 1;
        c = R_c;
        while (r >= 0 && board[r][c] == '.') r--;
        if (r >= 0 && board[r][c] == 'p') ans++;

        // left
        r = R_r;
        c = R_c - 1;
        while (c >= 0 && board[r][c] == '.') c--;
        if (c >= 0 && board[r][c] == 'p') ans++;

        // bot
        r = R_r + 1;
        c = R_c;
        while (r < n && board[r][c] == '.') r++;
        if (r < n && board[r][c] == 'p') ans++;

        // right
        r = R_r;
        c = R_c + 1;
        while (c < n && board[r][c] == '.') c++;
        if (c < n && board[r][c] == 'p') ans++;

        return ans;
    }
};

int main() {
	// Solution
	Solution sol;

	// Test cases

}