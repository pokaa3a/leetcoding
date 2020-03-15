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
//     int subarraysWithKDistinct(vector<int>& A, int K) {
//     	int n = A.size();
//     	int left = 0, right = 0, end = 0, ans = 0;
//     	unordered_map<int, int> count;
//     	while (right < n + 1) {
//     		if (right < n && count.size() < K) {
//     			count[A[right++]]++;
//     		} else if (count.size() == K) {
//     			end = right;
//     			while (end < n && count.find(A[end]) != count.end()) end++;
//     			while (count.size() == K) {
//     				// cout << "lft: " << left << ", rht: " << right << ", end: " << end << endl;
//     				ans += end - right + 1;
//     				int tmp = A[left++];
//     				if (--count[tmp] == 0) count.erase(tmp);
//     			}
//     		} else {
//     			right++;
//     		}
//     	}
//     	return ans;
//     }
// };

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return helper(A, K) - helper(A, K - 1);
    }
private:
	int helper(vector<int>& A, int K) {
		int n = A.size();
		unordered_map<int, int> count;
		int ans = 0, i = 0;
		for (int j = 0; j < n; ++j) {
			count[A[j]]++;
			while (count.size() > K) {
				if (--count[A[i]] == 0) {
					count.erase(A[i]);
				}
				i++;
			}
			ans += j - i + 1;
		}
		return ans;
	}
};

int main() {
	// Solution
	Solution sol;

	// Test cases
	int a[] = {1,2,1,2,3};
	vector<int> A(a, a + 5);
	int K = 2;
	cout << sol.subarraysWithKDistinct(A, K) << endl;

}