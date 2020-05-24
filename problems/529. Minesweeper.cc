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
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int rows = board.size();
        int cols = board[0].size();
        
        int r = click[0], c = click[1];
        // check if it's a mine
        if (board[r][c] == 'M') {
            board[r][c] = 'X';
            return board;
        }
        // check adjacnet mines
        int mines = 0;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) continue;
                int r_n = r + i, c_n = c + j;
                if (r_n >= 0 && r_n < rows && c_n >= 0 && c_n < cols &&
                    board[r_n][c_n] == 'M') mines++;
            }
        }
        if (mines > 0) {
            board[r][c] = char(mines + '0');
            return board;
        } else {
            board[r][c] = 'B';
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (i == 0 && j == 0) continue;
                    int r_n = r + i, c_n = c + j;
                    if (r_n >= 0 && r_n < rows && c_n >= 0 && c_n < cols &&
                        board[r_n][c_n] == 'E') {
                        vector<int> next_click = {r_n, c_n};
                        updateBoard(board, next_click);
                    }
                }
            }
        }
        return board;
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