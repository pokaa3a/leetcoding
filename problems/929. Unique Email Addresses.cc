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
    int numUniqueEmails(vector<string>& emails) {
        set<string> counts;
        for (int i = 0; i < emails.size(); ++i) {
        	string rectified_email = rectify(emails[i]);
        	// cout << rectified_email << endl;
        	counts.insert(rectified_email);
        }
        return counts.size();
    }
    string rectify(string email) {
    	string domain = email.substr(email.find('@') + 1);
    	string local = email.substr(0, email.find('@'));
    	local = local.substr(0, local.find('+'));

    	string true_local = "";
    	stringstream ss(local);
    	string token;
    	while (getline(ss, token, '.')) {
    		true_local += token;
    	}
    	return true_local + "@" + domain;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */

	/* [1-D vector] */
	// const int a = 1;
	// int arr[] = {};
	// vector<int> nums(arr, arr + a);
	string s[] = {"test.email+alex@leetcode.com",
				  "test.e.mail+bob.cathy@leetcode.com", 
				  "testemail+david@lee.tcode.com"};
	vector<string> emails(s, s + 3);

	cout << sol.numUniqueEmails(emails) << endl;

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