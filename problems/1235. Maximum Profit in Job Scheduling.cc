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
//     int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
//         int n = startTime.size();
//         vector<vector<int> > jobs;
//         for (int i = 0; i < n; ++i) {
//         	int j[] = {endTime[i], startTime[i], profit[i]};
//             vector<int> job(j, j + 3);
//             jobs.push_back(job);
//         }
//         sort(jobs.begin(), jobs.end());
        
//         vector<int> dp_end(1, 0);
//         vector<int> dp_pro(1, 0);
        
//         int ans = 0;
//         for (int i = 0; i < n; ++i) {
//             int t_start = jobs[i][1];
//             int t_end = jobs[i][0];
//             int prof = jobs[i][2];
//             // cout << "(" << t_start << ", " << t_end << ", " << prof << ")" << endl;
//             int found = upper_bound(dp_end.begin(), dp_end.end(), t_start) - dp_end.begin() - 1;
//             // cout << "found: " << found << endl;

//             int max_prof = dp_pro[found] + prof;
//             ans = max(ans, max_prof);
//             if (dp_end.back() == t_end) {
//                 dp_pro.back() = max(dp_pro.back(), max_prof);
//             } else {
//             	if (max_prof > dp_pro.back()) {
// 	                dp_end.push_back(t_end);
// 	                dp_pro.push_back(max_prof);
//             	}
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
	int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
		int n = startTime.size();
		vector<vector<int> > jobs;
		for (int i = 0; i < n; ++i) {
			int a[] = {endTime[i], i};
			jobs.push_back(vector<int>(a, a + 2));
		}
		sort(jobs.begin(), jobs.end());

		// define state: dp[i] == max profit from first i jobs
		vector<int> dp(n + 1, 0);
		dp[0] = 0;
		for (int i = 1; i <= n; ++i) {
			// search for biggest j, s.t. endTime[j] (jobs[][0]) <= startTime[i]
			int lo = 0, hi = n - 1;
			while (lo < hi) {
				int mi = lo + (hi - lo + 1) / 2;
				if (jobs[mi][0] <= startTime[jobs[i - 1][1]]) lo = mi;
				else hi = mi - 1;
			}
			if (jobs[lo][0] <= startTime[jobs[i - 1][1]])
				dp[i] = max(dp[i - 1], dp[lo + 1] + profit[jobs[i - 1][1]]);
			else
				dp[i] = max(dp[i - 1], profit[jobs[i - 1][1]]);
			// cout << "j = " << lo << endl;	
			// cout << "dp[i] = " << dp[i] << endl;
		}
		return dp[n];
	}
};


int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	// int s[] = {4,2,4,8,2};
	int s[] = {1,1,1};
	// int e[] = {5,5,5,10,8};
	int e[] = {2,3,4};
	// int p[] = {1,2,8,10,4};
	int p[] = {5,6,4};
	vector<int> startTime(s, s + 3);
	vector<int> endTime(e, e + 3);
	vector<int> profit(p, p + 3);

	cout << sol.jobScheduling(startTime, endTime, profit) << endl;

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