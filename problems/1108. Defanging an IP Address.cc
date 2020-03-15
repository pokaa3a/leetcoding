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
    string defangIPaddr(string address) {
        string ans = "";
        for (int i = 0; i < address.size(); i++) {
        	if (address[i] == '.') {
        		ans += "[.]";
        	} else {
        		ans += address[i];
        	}
        }
        return ans;
    }
};

int main() {
	// Solution
	Solution sol;

	// Test cases

}