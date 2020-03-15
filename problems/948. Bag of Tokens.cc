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
#include <numeric>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/* Solution */
const int MOD = 1000000007;
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
    	if (tokens.size() == 0) return 0;
        sort(tokens.begin(), tokens.end());

        int left = 0, right = tokens.size();
        int score = 0;
        while (left <= right) {
        	while (left < tokens.size() && P >= tokens[left] && left <= right) {
        		P -= tokens[left];
        		left++;
        		score++;
        	}
        	if (score == 0) break;
        	right--;
        	if (right <= left) break;
        	P += tokens[right];
        	score--;
        }
        return score;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	int P = 54;
	int t[] = {71,55,82};
	vector<int> tokens(t, t + 3);

	cout << sol.bagOfTokensScore(tokens, P) << endl;

	/* [1-D vector] */
	// const int a = 1;
	// int arr[] = {};
	// vector<int> nums(arr, arr + a);

	/* [2-D vector] */
	// const int rows = 1;
	// const int cols = 1;
	// int arr[rows][cols] = {{1}};
	// vector<vector<int> > grid;
	// for (int r = 0; r < rows; ++r) {
	// 	grid.push_back(vector<int>(arr[r], arr[r] + cols));
	// }

	/* [String] */
	// string str = "";

}