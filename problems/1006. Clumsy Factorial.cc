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
    int clumsy(int N) {
        vector<int> add;
        vector<int> subtract;

        if (N == 1) return 1;
        if (N == 2) return 2 * 1;

        add.push_back(N * (N - 1) / (N - 2));
        for (int i = N - 3; i >= 1; i -= 4) {
        	add.push_back(i);
        }

        if (N > 4) {
        	for (int i = N - 4; i >= 1; i -= 4) {
        		if (i == 1) subtract.push_back(1);
        		else if (i == 2) subtract.push_back(2 * 1);
        		else subtract.push_back(i * (i - 1) / (i - 2));
        	}
        }

        long long ans = 0;
        for (int i = 0; i < add.size(); ++i) ans += add[i];
        for (int i = 0; i < subtract.size(); ++i) ans -= subtract[i];

        return (int)ans;
    }
};

int main() {
	// Solution
	Solution sol;

	// Test cases
	cout << sol.clumsy(10000) << endl;
}