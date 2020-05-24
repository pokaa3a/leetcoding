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
    void solveSudoku(vector<vector<char>>& board) {
        helper(0, 0, board);
    }
    bool helper(int r, int c, vector<vector<char>>& board) {
    	r += c / 9;
    	c %= 9;
    	if (r == 9) return true;
    	if (isdigit(board[r][c])) {
    		return helper(r, c + 1, board);
    	}
    	// baord[r0][c0] = '.'
    	for (int num = 1; num <= 9; num++) {
    		board[r][c] = char(num + '0');
    		if (isValid(r, c, board)) {
    			if (helper(r, c + 1, board)) return true;
    		}
    	}
    	board[r][c] = '.';
    	return false;
    }
    bool isValid(int r, int c, vector<vector<char>>& board) {
        // check row r
        vector<bool> row(10, false);
        for (int i = 0; i < 9; i++) {
            if (isdigit(board[r][i])) {
                if (row[board[r][i] - '0']) return false;
                row[board[r][i] - '0'] = true;
            }
        }

        // check col c
        vector<bool> col(10, false);
        for (int i = 0; i < 9; i++) {
            if (isdigit(board[i][c])) {
                if (col[board[i][c] - '0']) return false;
                col[board[i][c] - '0'] = true;
            }
        }

        // check block
        vector<bool> block(10, false);
        int r0 = (r / 3) * 3, c0 = (c / 3) * 3;
        for (int i = r0; i < r0 + 3; i++) {
            for (int j = c0; j < c0 + 3; j++) {
            	if (isdigit(board[i][j])) {
	                if (block[board[i][j] - '0']) return false;
	                block[board[i][j] - '0'] = true;
            	}
            }
        }
        return true;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},
								  {'6','.','.','1','9','5','.','.','.'},
								  {'.','9','8','.','.','.','.','6','.'},
								  {'8','.','.','.','6','.','.','.','3'},
								  {'4','.','.','8','.','3','.','.','1'},
								  {'7','.','.','.','2','.','.','.','6'},
							 	  {'.','6','.','.','.','.','2','8','.'},
								  {'.','.','.','4','1','9','.','.','5'},
								  {'.','.','.','.','8','.','.','7','9'}};
	sol.solveSudoku(board);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
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