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
// class Solution {
// public:
//     bool canMeasureWater(int x, int y, int z) {
//     	   if (z == 0) return true;
//         if (z > x + y) return false;
//         if (x % 2 == 0 && y % 2 == 0 && z % 2 == 1) return false;

//         set<int> targets;
//         targets.insert(z);
//         if (z > x) targets.insert(z - x);
//         if (z > y) targets.insert(z - y);

//         set<int> measurable;

//         queue<int> q;
//         q.push(x);
//         q.push(y);

//         while (!q.empty()) {
//         	int w = q.front(); q.pop();

//         	for (int i = 1; w - i * x >= 0; ++i) {
//         		if (measurable.count(w - i * x) == 0) {
//         			if (targets.count(w - i * x) > 0) return true;
//         			q.push(w - i * x);
//         			measurable.insert(w - i * x);
//         		}
//         	}
//         	for (int i = 1; w - i * y >= 0; ++i) {
//         		if (measurable.count(w - i * y) == 0) {
//         			if (targets.count(w - i * y) > 0) return true;
//         			q.push(w - i * y);
//         			measurable.insert(w - i * y);
//         		}
//         	}
//         	for (int i = 1; w + i * x <= y; ++i) {
//         		if (measurable.count(w + i * x) == 0) {
//         			if (targets.count(w + i * x) > 0) return true;
//         			q.push(w + i * x);
//         			measurable.insert(w + i * x);
//         		}
//         	}
//         	for (int i = 1; w + i * y <= x; ++i) {
//         		if (measurable.count(w + i * y) == 0) {
//         			if (targets.count(w + i * y) > 0) return true;
//         			q.push(w + i * y);
//         			measurable.insert(w + i * y);
//         		}
//         	}
//         	if (x > w) {
//         		int i = 1;
//         		while (i * y <= (x - w)) i++;
//         		if (measurable.count(i * y - (x - w)) == 0) {
//         			if (targets.count(i * y - (x - w)) > 0) return true;
//         			q.push(i * y - (x - w));
//         			measurable.insert(i * y - (x - w));
//         		}
//         	}
//         	if (y > w) {
//         		int i = 1;
//         		while (i * x <= (y - w)) i++;
//         		if (measurable.count(i * x - (y - w)) == 0) {
//         			if (targets.count(i * x - (y - w)) > 0) return true;
//         			q.push(i * x - (y - w));
//         			measurable.insert(i * x - (y - w));
//         		}
//         	}
//         }
//         return false;
//     }
// };

class Solution {
public:
	int canMeasureWater(int x, int y, int z) {
		if (z == 0) return true;
		if (z > x + y) return false;
		if (z % gcd(x, y) == 0) return true;
		return false;
	}
	int gcd(int a, int b) {
		if (a == 0) return b;
		return gcd(b % a, a);
	}
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	int x = 2, y = 6, z = 5;
	cout << sol.canMeasureWater(x, y, z) << endl;

	/* [1-D vector] */
	// const int a = 1;
	// int arr[] = {};
	// vector<int> nums(arr, arr + a);

	/* [2-D vector] */
	// const int rows = 1;
	// const int cols = 1;
	// int arr[rows][cols] = {{1}};
	// vector<vector<int> > grid;
	// for (int r = 0; r < rows; ++r) {
	// 	grid.push_back(vector<int>(arr[r], arr[r] + cols));
	// }

	/* [String] */
	// string str = "";

}