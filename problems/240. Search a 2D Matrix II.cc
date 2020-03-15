#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int> > &matrix, int target) {
		int num_rows = matrix.size();
        if (!num_rows) return false;
		int num_cols = matrix[0].size();
        if (!num_cols) return false;

        int row = 0, col = num_cols - 1;
        while (row < num_rows && col >= 0) {
        	if (matrix[row][col] == target) return true;
        	if (matrix[row][col] > target) col--;
        	if (matrix[row][col] < target) row++;
        }
        return false;
	}
};

int main() {

	int row0[] = {1,   4,  7, 11, 15};
	int row1[] = {2,   5,  8, 12, 19};
	int row2[] = {3,   6,  9, 16, 22};
	int row3[] = {10, 13, 14, 17, 24};
	int row4[] = {18, 21, 23, 26, 30};

	vector<vector<int> > matrix;
	matrix.push_back(vector<int>(row0, row0 + 5));
	matrix.push_back(vector<int>(row1, row1 + 5));
	matrix.push_back(vector<int>(row2, row2 + 5));
	matrix.push_back(vector<int>(row3, row3 + 5));
	matrix.push_back(vector<int>(row4, row4 + 5));

	int target = 20;

	Solution sol;
	cout << sol.searchMatrix(matrix, target);

}