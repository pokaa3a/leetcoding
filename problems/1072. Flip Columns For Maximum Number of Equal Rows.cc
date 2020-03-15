#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int> >& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        map<string, int> hash;

        int res = 0;
        for (int i = 0; i < rows; ++i) {
        	string key = "";
        	bool to_flip = matrix[i][0] == 0 ? true : false;
        	for (int j = 0; j < cols; ++j) {
        		if (to_flip) {
        			if (matrix[i][j] == 0) {
        				key += '1';
        			} else {
        				key += '0';
        			}
        		} else {
        			if (matrix[i][j] == 0) {
        				key += '0';
        			} else {
        				key += '1';
        			}
        		}
        	}
        	// cout << "key: " << key << endl;
        	res = max(res, ++hash[key]);
        }
        return res;
    }
};

int main() {
	int r1[] = {0, 0, 0};
	int r2[] = {0, 0, 1};
	int r3[] = {1, 1, 0};
	vector<vector<int> > matrix;
	matrix.push_back(vector<int>(r1, r1 + 3));
	matrix.push_back(vector<int>(r2, r2 + 3));
	matrix.push_back(vector<int>(r3, r3 + 3));

	Solution sol;
	cout << sol.maxEqualRowsAfterFlips(matrix) << endl;
}