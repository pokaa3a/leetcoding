#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
    	int res = 0, m = 0;
    	for (int x = -1; x <= 1; x += 2) {
    		for (int y = -1; y <= 1; y += 2) {
    			m = x * arr1[0] + y * arr2[0] + 0;
    			for (int i = 0; i < arr1.size(); ++i) {
    				int val = x * arr1[i] + y * arr2[i] + i;
    				res = max(res, val - m);
    				m = min(m, val);
    			}
    		}
    	}
    	return res;
    }
};

int main() {
	int a1[] = {1, -2};
	vector<int> arr1(a1, a1 + 2);
	int a2[] = {8, 8};
	vector<int> arr2(a2, a2 + 2);
	Solution sol;
	cout << sol. maxAbsValExpr(arr1, arr2) << endl;
}