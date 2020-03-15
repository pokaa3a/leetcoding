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
    bool queryString(string S, int N) {
        for (int n = N; n > N / 2; --n) {
        	string b = bitset<32>(n).to_string();
        	if (S.find(b.substr(b.find("1"))) == string::npos) return false;
        }
        return true;
    }
};

int main() {
	// Solution
	Solution sol;

	// Test cases
	string S = "1";
	int N = 1;
	cout << sol.queryString(S, N) << endl;

}