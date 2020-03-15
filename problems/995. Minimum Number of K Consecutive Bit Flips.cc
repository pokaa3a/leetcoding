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
    int minKBitFlips(vector<int>& A, int K) {
    	queue<int> q;
    	int ans = 0;
    	for (int i = 0; i < A.size(); ++i) {
    		if ((A[i] + q.size()) % 2 == 0) {
    			// cout << i + K - 1 << endl;
    			q.push(i + K - 1);
    			ans++;
    		}
    		if (!q.empty() && q.front() == i) q.pop();
    	}
    	return q.size() == 0 ? ans : -1;
    }
};

int main() {
	// Solution
	Solution sol;

	// Test cases
	int a[] = {0,0,0,1,0,1,1,0};
	vector<int> A(a, a + 8);
	int K = 3;
	cout << sol.minKBitFlips(A, K) << endl;

}