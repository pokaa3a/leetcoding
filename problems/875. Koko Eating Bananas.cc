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
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int lo = 1, hi = 1e9;

        while (lo < hi) {
        	int K = (lo + hi) / 2;
        	// K is too big
        	if (eating_time(piles, K) <= H) hi = K;
        	// K is too small
        	else lo = K + 1;
        }
        return lo;
    }
    int eating_time(vector<int>& piles, int K) {
    	int hours = 0;
    	for (int i = 0; i < piles.size(); ++i) {
    		int h = piles[i] / K;
    		hours += K * h < piles[i] ? h + 1 : h;
    	}
    	return hours;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	int p[] = {30,11,23,4,20}, H = 6;
	vector<int> piles(p, p + 5);

	cout << sol.minEatingSpeed(piles, H) << endl;

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