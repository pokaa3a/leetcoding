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
class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
    	long long left = 1, right = 2 * 1e9;
    	while (left < right) {
    		long long mid = (left + right) / 2;
    		long long cnt = count(mid, a, b, c);
    		if (cnt < n) {
    			left = mid + 1;
    		} else {
    			right = mid;
    		}
    	}
    	return (int)left;
    }
    long long gcd(long long a, long long b) {
    	if (a == 0) return b;
    	return gcd(b % a, a);
    }
    long long lcm(long long a, long long b) {
    	return a * b / gcd(a, b);
    }
    long long count(long long n, long long a, long long b, long long c) {
    	return n / a + n / b + n / c 
    		   - n / lcm(a, b) - n / lcm(b, c) - n / lcm(a, c)
    		   + n / lcm(lcm(a, b), c);
    }
};


int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	int n = 5, a = 2, b = 11, c = 13;
	cout << sol.nthUglyNumber(n, a, b, c) << endl;

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