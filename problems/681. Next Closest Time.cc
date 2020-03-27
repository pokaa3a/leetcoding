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
public:
    string nextClosestTime(string time) {
        vector<int> digits;
        set<int> ss;
        for (int i = 0; i < 5; i++) {
        	if (i == 2) continue;
        	ss.insert(time[i] - '0');
        }
        while (!ss.empty()) {
        	digits.push_back(*ss.begin());
        	ss.erase(ss.begin());
        }

        string next_time = time;
        for (int i = 4; i >= 0; i--) {
        	if (i == 2) continue;
        	int next = next_digit(next_time[i] - '0', digits);
        	if (next < 0) {
        		next_time[i] = '0' + digits.front();
        	} else {
        		string tmp = next_time;
        		tmp[i] = '0' + next;
        		if (is_valid(tmp)) return tmp;
        		else {
        			next_time[i] = '0' + digits.front();
        		}
        	}
        }
        return next_time;
    }
    bool is_valid(string time) {
    	int HH = stoi(time.substr(0, 2));
    	int MM = stoi(time.substr(3));
    	if (HH > 23) return false;
    	if (MM > 59) return false;
    	return true;
    }
    int next_digit(int num, vector<int>& digits) {
    	for (int i = 0; i < digits.size() - 1; i++) {
    		if (digits[i] == num) return digits[i + 1];
    	}
    	return -1;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	string s = "23:54";
	cout << sol.nextClosestTime(s) << endl;

	/* [1-D vector] */
	// int arr[] = {};
	// vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));

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