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
using namespace std;

const int MOD = 1000000007;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* Solution */
class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int min_A = INT_MAX;
        for (int i = 1; i <= 6; ++i) {
        	int count = 0;
        	bool valid = true;
        	for (int k = 0; k < A.size(); ++k) {
        		if (A[k] != i) {
        			if (B[k] == i) count++;
        			else {
        				valid = false;
        				break;
        			}
        		}
        	}
        	min_A = valid ? min(min_A, count) : min_A;
        }
        int min_B = INT_MAX;
        for (int i = 1; i <= 6; ++i) {
        	int count = 0;
        	bool valid = true;
        	for (int k = 0; k < B.size(); ++k) {
        		if (B[k] != i) {
        			if (A[k] == i) count++;
        			else {
        				valid = false;
        				break;
        			}
        		}
        	}
        	min_B = valid ? min(min_B, count) : min_B;
        }
        if (min_A == INT_MAX && min_B == INT_MAX) return -1;
        return min(min_A, min_B);
    }
};

int main() {
	// Solution
	Solution sol;

	// Test cases

}