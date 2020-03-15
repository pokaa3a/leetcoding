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
    bool isBoomerang(vector<vector<int> >& points) {
        pair<int, int> v01 = make_pair(points[1][0] - points[0][0], points[1][1] - points[0][1]);
        pair<int, int> v21 = make_pair(points[2][0] - points[1][0], points[2][1] - points[1][1]);

        if ((v01.first == 0 && v01.second == 0) || (v21.first == 0 && v21.second == 0)) return false;
        if ((v01.first == 0 && v21.first == 0) || (v01.second == 0 && v21.second == 0)) return false;

        return double(v01.first) / double(v21.first) != double(v01.second) / double(v21.second);
    }
};

int main() {
	// Solution
	Solution sol;

	// Test cases

}