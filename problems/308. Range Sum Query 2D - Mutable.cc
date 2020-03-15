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

/* Solution */
const int MOD = 1000000007;
class NumMatrix {
	int rows, cols;
	vector<vector<int> > row_sums;
	vector<vector<int> > matrix_;
public:
    NumMatrix(vector<vector<int> >& matrix) {
        rows = matrix.size();
        if (rows > 0) cols = matrix[0].size();
        else cols = 0;
        
        row_sums = vector<vector<int> >(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; ++i) {
        	for (int j = 0; j < cols; ++j) {
        		row_sums[i][j] = j == 0 ? matrix[i][j] : row_sums[i][j - 1] + matrix[i][j];
        	}
        }
        matrix_ = matrix;
    }
    
    void update(int row, int col, int val) {
        int diff = val - matrix_[row][col];
        for (int j = col; j < cols; ++j) {
        	row_sums[row][j] += diff;
        }
        matrix_[row][col] = val;
        // for (int i = 0; i < rows; ++i) {
        // 	for (int j = 0; j < cols; ++j) {
        // 		cout << row_sums[i][j] << " ";
        // 	}
        // 	cout << endl;
        // }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        if (col1 == 0) {
			for (int i = row1; i <= row2; ++i) {
	        	sum += row_sums[i][col2];
	        }  
        } else {
			for (int i = row1; i <= row2; ++i) {
	        	sum += row_sums[i][col2] - row_sums[i][col1 - 1];
	        }        	
        }
        return sum;
    }
};

int main() {
	/* Solution */

	/* Test cases */

	/* [1-D vector] */
	// const int a = 1;
	// int arr[] = {};
	// vector<int> nums(arr, arr + a);

	/* [2-D vector] */
	const int rows = 2;
	const int cols = 2;
	// int arr[rows][cols] = {{3, 0, 1, 4, 2},
	// 					   {5, 6, 3, 2, 1},
	// 					   {1, 2, 0, 1, 5},
	// 					   {4, 1, 0, 1, 7},
	// 					   {1, 0, 3, 0, 5}};
	int arr[rows][cols] = {{2,4},
						   {-3,5}};
	vector<vector<int> > grid;
	for (int r = 0; r < rows; ++r) {
		grid.push_back(vector<int>(arr[r], arr[r] + cols));
	}

	NumMatrix nm(grid);

	nm.update(0, 1, 3);
	nm.update(1, 1, -3);
	nm.update(0, 1, 1);
	cout << nm.sumRegion(0,0,1,1) << endl;
	/* [String] */
	// string str = "";

}