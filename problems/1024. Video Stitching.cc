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
    int videoStitching(vector<vector<int> >& clips, int T) {
    	vector<int> max_len(101, 0);
    	for (int i = 0; i < clips.size(); ++i) {
    		max_len[clips[i][0]] = max(max_len[clips[i][0]], clips[i][1]);
    	}

    	int clip = max_len[0], next_clip = max_len[0], ans = 1;
    	if (clip >= T) return ans;
    	for (int i = 1; i <= T; ++i) {
    		if (i <= clip) {
    			next_clip = max(next_clip, max_len[i]);
    		}
    		if (i == clip) {
    			clip = next_clip;
    			ans++;
    			if (clip >= T) return ans;
    		}
    	}
    	return -1;
    }
};

int main() {
	// Solution
	Solution sol;

	// Test cases


}