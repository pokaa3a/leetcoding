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
    vector<vector<int> > candyCrush(vector<vector<int> >& board) {
        drop(board);
        while (crush(board)) drop(board);
        clean_board(board);
        return board;
    }
    void clean_board(vector<vector<int> >& board) {
        for (int r = 0; r < board.size(); r++) {
        	for (int c = 0; c < board[0].size(); c++) {
        		board[r][c] = board[r][c] > 3000 ? 0 : board[r][c];
        	}
        }
    }

    void drop(vector<vector<int> >& board) {
    	int rows = board.size(), cols = board[0].size();
    	for (int c = 0; c < cols; c++) {
    		int r_empty = rows - 1;
    		while (r_empty > 0 && board[r_empty][c] > 0 && board[r_empty][c] < 3000) r_empty--;

    		while (r_empty > 0) {
    			int r_occu = r_empty - 1;
    			while (r_occu >= 0 && (board[r_occu][c] == 0 || board[r_occu][c] > 3000)) r_occu--;
    			if (r_occu >= 0) {
    				board[r_empty][c] = 0;
    				swap(board[r_empty--][c], board[r_occu--][c]);
    			} else {
    				break;
    			}
    		}
    	}
    }
    bool crush(vector<vector<int> >& board) {
    	int rows = board.size(), cols = board[0].size();
    	bool any_crushed = false;
    	for (int r = 0; r < rows; r++) {
    		for (int c = 0; c < cols; c++) {
    			if (board[r][c] == 0) continue;
    			int candy = board[r][c] > 3000 ? board[r][c] - 3000 : board[r][c];
    			bool crushed = false;
    			// up
    			if (try_crush(r, c, -1, 0, board)) crushed = true;
    			// down
    			if (try_crush(r, c, 1, 0, board)) crushed = true;
    			// left
    			if (try_crush(r, c, 0, -1, board)) crushed = true;
    			// right
    			if (try_crush(r, c, 0, 1, board)) crushed = true;

    			if (crushed) board[r][c] = candy + 3000;
    			any_crushed |= crushed;
    		}
    	}
    	clean_board(board);
    	return any_crushed;
    }
    bool try_crush(int r, int c, int r_add, int c_add, vector<vector<int> >& board) {
    	int rows = board.size(), cols = board[0].size();
    	int candy = board[r][c] > 3000 ? board[r][c] - 3000 : board[r][c], k = 1;
    	while (r + k * r_add >= 0 && r + k * r_add < rows &&
    		   c + k * c_add >= 0 && c + k * c_add < cols &&
    		   (board[r + k * r_add][c + k * c_add] == candy ||
    		   	board[r + k * r_add][c + k * c_add] == 3000 + candy)) {
    		k++;
    	}
    	if (k >= 3) {
    		for (int i = 1; i < k; i++) {
    			board[r + i * r_add][c + i * c_add] = 3000 + candy;
    		}
    		return true;
    	}
    	return false;
    }
    void print_board(vector<vector<int> >& board) {
    	int rows = board.size(), cols = board[0].size();
    	cout << string(cols * 2, '=') << endl;
    	for (int r = 0; r < rows; r++) {
    		for (int c = 0; c < cols; c++) {
    			cout << board[r][c] << " ";
    		}
    		cout << endl;
    	}
    	cout << string(cols * 2, '=') << endl;
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
	const int rows = 10;
	const int cols = 5;
	int arr[rows][cols] = {{110,5,112,113,114},
						   {210,211,5,213,214},
						   {310,311,3,313,314},
						   {410,411,412,5,414},
						   {5,1,512,3,3},
						   {610,4,1,613,614},
						   {710,1,2,713,714},
						   {810,1,2,1,1},
						   {1,1,2,2,2},
						   {4,1,4,4,1014}};
	vector<vector<int> > grid;
	for (int r = 0; r < rows; ++r) {
		grid.push_back(vector<int>(arr[r], arr[r] + cols));
	}

	// sol.print_board(grid);
	// sol.crush(grid);
	// sol.print_board(grid);
	sol.candyCrush(grid);
	sol.print_board(grid);

	/* [String] */
	// string str = "";

}