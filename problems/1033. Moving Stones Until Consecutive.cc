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
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> stones;
        stones.push_back(a);
        stones.push_back(b);
       	stones.push_back(c);
       	sort(stones.begin(), stones.end());

       	int lft_mini = 2, rht_mini = 2;
       	if (stones[0] + 2 >= stones[1]) lft_mini--;
       	if (stones[0] + 2 >= stones[2]) lft_mini--;
       	if (stones[2] - 2 <= stones[1]) rht_mini--;
       	if (stones[2] - 2 <= stones[0]) rht_mini--;
       	int mini = min(lft_mini, rht_mini);

       	int maxi = (stones[2] - stones[1] - 1) + (stones[1] - stones[0] - 1);
       	int arr[] = {mini, maxi};
       	return vector<int>(arr, arr + 2);
    }
};

int main() {
	// Solution
	Solution sol;

	// Test cases
	int a = 1, b = 9, c = 5;
	vector<int> ans = sol.numMovesStones(a, b, c);
	for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
	cout << endl;

}