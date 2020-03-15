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
    vector<string> commonChars(vector<string>& A) {
        vector<int> global_dict(26, 0);

        for (int i = 0; i < A.size(); ++i) {
        	vector<int> local_dict(26, 0);
        	for (int j = 0; j < A[i].size(); ++j) {
        		local_dict[A[i][j] - 'a']++;
        	}
        	if (i == 0) global_dict = local_dict;
        	for (int k = 0; k < 26; ++k) {
        		if (global_dict[k] >= local_dict[k]) global_dict[k] = local_dict[k];
        	}
        }
        vector<string> ans;
        for (int i = 0; i < 26; ++i) {
        	if (global_dict[i] > 0) {
        		for (int j = 0; j < global_dict[i]; ++j) {
        			string tmp = "";
        			tmp += char(i + 'a');
        			ans.push_back(tmp);
        		}
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