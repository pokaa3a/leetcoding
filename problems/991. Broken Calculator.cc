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
// class Solution {
// public:
//     int brokenCalc(int X, int Y) {
//     	if (X > Y) return X - Y;

//     	int count = 0;
//     	while (X < Y) {
//     		X *= 2;
//     		count++;
//     	}
//     	int ans = count;
//     	X -= Y;
//     	while (X > 0) {
//     		int p = 1;
//     		while (p <= X && p <= pow(2, count)) p *= 2;
//     		X -= p / 2;
//     		ans++;
//     	}
//         return ans;
//     }
// };

class Solution {
public:
    int brokenCalc(int X, int Y) {
		int ans = 0;
		while (Y > X) {
			ans++;
			if (Y % 2 == 1) Y++;
			else Y /= 2;
		}
		return ans + X - Y;
    }
};

int main() {
	// Solution
	Solution sol;

	// Test cases
	int X = 5, Y = 6;
	cout << sol.brokenCalc(X, Y) << endl;
}