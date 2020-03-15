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

// class Solution {
// public:
//     int kConcatenationMaxSum(vector<int>& arr, int k) {
//         int n = arr.size();
//         vector<long long> sums(n, 0);
//         for (int i = 0; i < n; ++i) {
//         	sums[i] = (i == 0 ? 0 : sums[i - 1]) + arr[i];
//         }

//         long long ans = 0;
//         if (sums.back() > 0) {
//         	long long mini = 0;
//         	for (int i = 0; i < n; ++i) {
//         		mini = min(mini, sums[i]);
//         		ans = max(sums[i] + sums.back() * (k - 1) - mini, ans);
//         	}
//         } else {
//         	long long mini = 0;
//         	for (int i = 0; i < n; ++i) {
//         		mini = min(mini, sums[i]);
//         		ans = max(sums[i] - mini, ans);
//         	}
//         	for (int i = 0; i < n; ++i) {
//         		ans = max(sums[i] + sums.back() - mini, ans);
//         	}
//         }
//         return ans % MOD;
//     }
// };

class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int n = arr.size();
        vector<long long> sums(n, 0);
        sums[0] = arr[0];
        for (int i = 1; i < n; ++i) {
            sums[i] = sums[i - 1] + arr[i];
        }
        
        long long ans = 0;
        // case-1
        long long small = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, (sums[i] - small) % MOD);
            small = min(small, sums[i]);
        }

        // case-2
        if (k >= 2) {
            for (int i = 0; i < n; ++i) {
                ans = max(ans, (sums[i] + sums.back() - small) % MOD);
            }
        }
        // case-3
        if (k >= 3 && sums.back() > 0) {
            for (int i = 0; i < n; ++i) {
                ans = max(ans, (sums[i] + (k - 1) * sums.back() - small) % MOD);
            }
        }
        return (int)ans;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */

	/* [1-D vector] */
	// const int a = 1;
	int arr[] = {-1,-2};
	int k = 7;
	vector<int> nums(arr, arr + 2);
	cout << sol.kConcatenationMaxSum(nums, k) << endl;

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