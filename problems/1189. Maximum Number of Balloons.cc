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
    int maxNumberOfBalloons(string text) {
        map<char, int> count;
        count['b'] = 0;
        count['a'] = 0;
        count['l'] = 0;
        count['o'] = 0;
        count['n'] = 0;
        for (int i = 0; i < text.size(); ++i) {
        	char c = text[i];
        	if (c == 'b') {
        		count[c]++;
        	} else if (c == 'a') {
        		count[c]++;
        	} else if (c == 'l') {
        		count[c]++;
        	} else if (c == 'o') {
        		count[c]++;
        	} else if (c == 'n') {
        		count[c]++;
        	}
        }

        int ans = INT_MAX;
        for (map<char, int>::iterator it = count.begin(); it != count.end(); ++it) {
        	if (it->first == 'l' || it->first == 'o') {
        		ans = min(ans, it->second / 2);
        	} else {
        		ans = min(ans, it->second);
        	}
        }
        return ans;
    }
};

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char, int> count;
        for (char c : text) {
            count[c]++;
        }
        int ans = INT_MAX;
        ans = min(ans, count['b']);
        ans = min(ans, count['a']);
        ans = min(ans, count['l'] / 2);
        ans = min(ans, count['o'] / 2);
        ans = min(ans, count['n']);
        return ans;
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