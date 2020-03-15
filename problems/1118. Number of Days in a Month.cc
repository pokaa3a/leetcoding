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
    int numberOfDays(int Y, int M) {
        if (M > 7) {
            return M % 2 == 0 ? 31 : 30;
        } else {
            if (M == 2) {
                return isLeap(Y) ? 29 : 28;
            } else {
                return M % 2 == 0 ? 30 : 31;
            }
        }
        return 0;
    }
    bool isLeap(int year) {
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
            return true;
        }
        return false;
    }
};

int main() {
	// Solution
	Solution sol;

	// Test cases

}