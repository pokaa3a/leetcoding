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
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans(queries.size(), false);
        for (int i = 0; i < queries.size(); ++i) {
        	ans[i] = helper(queries[i], pattern);
        }
        return ans;
    }
    bool helper(string query, string pattern) {
    	int j = 0;
    	for (int i = 0; i < pattern.size(); ++i) {
    		char p = pattern[i];
    		while (j < query.size() && query[j] != p) {
    			if (query[j] >= 'A' && query[j] <= 'Z') return false;
    			j++;
    		}
    		if (j == query.size()) return false;
    		j++;
    	}
    	for (;j < query.size(); ++j) {
    		if (query[j] >= 'A' && query[j] <= 'Z') return false;
    	}
    	return true;
    }
};

int main() {
	// Solution
	Solution sol;

	// Test cases

}