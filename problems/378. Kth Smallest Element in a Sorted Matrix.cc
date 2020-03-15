#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	int kthSmallest(vector<vector<int> > &matrix, int k) {
		priority_queue<int> heap;
		for (int r = 0; r < matrix.size(); r++) {
			for (int c = 0; c < matrix[r].size(); c++) {
				heap.push(matrix[r][c]);
				if (heap.size() > k) heap.pop();
			}
		}
		return heap.top();
	}
};

int main() {
	int r0[] = {1, 5, 9};
	vector<int> row0(r0, r0 + 3);
	int r1[] = {10, 11, 13};
	vector<int> row1(r1, r1 + 3);
	int r2[] = {12, 13, 15};
	vector<int> row2(r2, r2 + 3);

	vector<vector<int> > matrix;
	matrix.push_back(row0);
	matrix.push_back(row1);
	matrix.push_back(row2);

	Solution sol;
	cout << sol.kthSmallest(matrix, 8) << endl;
}