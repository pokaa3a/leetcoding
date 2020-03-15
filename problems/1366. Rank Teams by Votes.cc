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

void traverse(TreeNode* root) {
	if (!root) return;
	cout << root->val << endl;
	traverse(root->left);
	traverse(root->right);
}

/* Solution */
const int MOD = 1000000007;
class Solution {
	struct cmp {
		bool operator() (const vector<int>& a, const vector<int>& b) {
			int n = a.size();

			// cout << char(a[0] + 'A') << ": ";
			// for (int i = 1; i < a.size(); ++i) cout << a[i] << " ";
			// cout << endl;
			// cout << char(b[0] + 'A') << ": ";
			// for (int i = 1; i < b.size(); ++i) cout << b[i] << " ";
			// cout << endl;

			for (int i = 1; i < n; ++i) {
				if (a[i] > b[i]) return true;
				else if (a[i] < b[i]) return false;
			}
			return a[0] < b[0];
		}
	};
public:
    string rankTeams(vector<string>& votes) {
    	int ranks = votes[0].size();
        vector<vector<int> > count(26, vector<int>(ranks + 1, 0));

        for (int i = 0; i < 26; ++i) {
        	count[i][0] = i;
        }

        for (int i = 0; i < votes.size(); ++i) {
        	for (int j = 0; j < votes[i].size(); ++j) {
        		count[votes[i][j] - 'A'][j + 1]++;
        	}
        }

        sort(count.begin(), count.end(), cmp());
        string ans = "";

        for (int i = 0; i < votes[0].size(); ++i) {
        	ans += char(count[i][0] + 'A');
        }
        return ans;
    }
};



int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	string v[] = {"WXYZ","XYZW"};
	vector<string> votes(v, v + 2);

	cout << sol.rankTeams(votes) << endl;

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