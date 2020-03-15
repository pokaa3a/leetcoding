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
    int longestArithSeqLength(vector<int>& A) {
        map<pair<int, int>, int> count;	// key = (idx, diff)
        int ans = 0;
        for (int i = 1; i < A.size(); ++i) {
        	int a = A[i];
        	for (int j = i - 1; j >= 0; --j) {
        		int diff = a - A[j];
        		if (count.find(make_pair(j, diff)) == count.end() &&
        			count.find(make_pair(i, diff)) == count.end()) {
        			count[make_pair(i, diff)] = 2;
        		} else {
        			if (count.find(make_pair(i, diff)) == count.end())
        				count[make_pair(i, diff)] = count[make_pair(j, diff)] + 1;
        			else 
        				count[make_pair(i, diff)] = max(count[make_pair(i, diff)], count[make_pair(j, diff)] + 1);
        		}
        		ans = max(ans, count[make_pair(i, diff)]);
        	}
        }
        return ans;
    }
};

int main() {
	// Solution
	Solution sol;

	// Test cases
	int n[] = {3,3,3,3};
	vector<int> nums(n, n + 4);
	cout << sol.longestArithSeqLength(nums) << endl;

}