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
    int maxScoreSightseeingPair(vector<int>& A) {
        int min_v = A[0] + 0, ans = INT_MIN;
        for (int j = 1; j < A.size(); ++j) {
        	int cur = A[j] - j;
        	ans = max(ans, cur + min_v);
        	min_v = max(min_v, A[j] + j);
        }
        return ans;
    }
};

int main() {
	// Solution
	Solution sol;

	// Test cases
	int a[] = {8,1,5,2,6};
	vector<int> A(a, a + 5);
	cout << sol.maxScoreSightseeingPair(A) << endl;
}