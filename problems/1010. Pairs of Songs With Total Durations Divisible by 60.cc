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
    int numPairsDivisibleBy60(vector<int>& time) {
        map<int, int> songs;
        int ans = 0;
        for (int i = 0; i < time.size(); ++i) {
        	int x = time[i] % 60;
        	if (songs.find((60 - x) % 60) != songs.end()) ans += songs[(60 - x) % 60];
        	songs[x]++;
        }
        return ans;
    }
};

int main() {
	// Solution
	Solution sol;

	// Test cases

}