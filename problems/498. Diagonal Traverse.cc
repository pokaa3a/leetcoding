#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> findDiagonalOrder(vector<vector<int> >& matrix) {
		int rows = matrix.size();
		if (!rows) return vector<int>();
		int cols = matrix[0].size();

		vector<int> res;
		bool isOdd = false;
		for (int sum = 0; sum < rows + cols - 1; ++sum) {
			// cout << "sum: " << sum << endl;
			int r_start = min(sum, rows - 1);
			int count_head = res.size();
			for (int r = r_start; r > max(sum - cols, -1); --r) {
				int c = sum - r;
				res.push_back(matrix[r][c]);
			}
			if (isOdd) {
				// cout << "reverse: " << count_head << endl;
				reverse(res.begin() + count_head, res.end());
			}
			isOdd = !isOdd;
		}
		return res;
	}
};

int main() {
	int row1[] = {1, 2, 3};
	int row2[] = {4, 5, 6};
	int row3[] = {7, 8, 9};

	vector<vector<int> > matrix;
	matrix.push_back(vector<int>(row1, row1 + 3));
	matrix.push_back(vector<int>(row2, row2 + 3));
	matrix.push_back(vector<int>(row3, row3 + 3));

	Solution sol;
	vector<int> path = sol.findDiagonalOrder(matrix);
	for (int i = 0; i < path.size(); ++i) cout << path[i] << " ";
	cout << endl;
}