#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int> >& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        for (int i = 0; i < rows; ++i) {
        	for (int j = 1; j < cols; ++j) {
        		matrix[i][j] += matrix[i][j - 1];
        	}
        }

        int res = 0;
        for (int i = 0; i < cols; ++i) {
        	for (int j = i; j < cols; ++j) {
        		map<int, int> count;
        		count[0] = 1;
        		int cur = 0;
        		for (int k = 0; k < rows; ++k) {
        			int sum = matrix[k][j] - (i == 0 ? 0 : matrix[k][i - 1]);
        			cur += sum;
        			if (count.find(cur - target) != count.end()) res += count[cur - target];
        			count[cur]++;
        		}
        	}
        }
        return res;
    }
};

int main() {
	int row1[] = {0, 1, 0};
	int row2[] = {1, 1, 1};
	int row3[] = {0, 1, 0};
	int target = 0;
	vector<vector<int> > matrix;
	matrix.push_back(vector<int>(row1, row1 + 3));
	matrix.push_back(vector<int>(row2, row2 + 3));
	matrix.push_back(vector<int>(row3, row3 + 3));

	Solution sol;
	cout << sol.numSubmatrixSumTarget(matrix, target) << endl;
}