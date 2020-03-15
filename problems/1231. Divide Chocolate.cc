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
    int maximizeSweetness(vector<int>& sweetness, int K) {
        int left = 1, right = 1e9 / K;
        while (left < right) {
        	int mid = (left + right) / 2;
        	int n_cuts = cut(mid, K, sweetness);
        	if (n_cuts <= K) {
        		right = mid;
        	} else {
        		left = mid + 1;
        	}
        }
        return left;
    }
    int cut(int w, int K, vector<int>& sweetness) {
    	int x = 0, n_cuts = 0;
    	for (int i = 0; i < sweetness.size(); ++i) {
    		if ((x += sweetness[i]) > w) {
    			x = 0;
    			if (++n_cuts > K) break;
    		}
    	}
    	return n_cuts;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	int s[] = {1,2,3,4,5,6,7,8,9};
	vector<int> sweetness(s, s + 9);
	int K = 5;
	cout << sol.maximizeSweetness(sweetness, K) << endl;

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