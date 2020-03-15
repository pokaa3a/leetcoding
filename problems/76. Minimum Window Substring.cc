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
// class Solution {
// 	unordered_map<char, int> t_chars;
// 	unordered_map<char, int> count;
// public:
//     string minWindow(string s, string t) {
//     	for (int i = 0; i < t.size(); ++i) {
//     		t_chars[t[i]]++;
//     	}

//     	int a = 0, b = 0, met = 0;
//     	while (b < s.size() && met < t_chars.size()) {
//     		if (t_chars.find(s[b]) != t_chars.end()) {
//     			count[s[b]]++;
//     			if (count[s[b]] == t_chars[s[b]]) met++;
//     		}
//     		b++;
//     	}
//     	if (b == s.size() && met < t_chars.size()) return "";
//     	b--;

//     	int range = b - a + 1;
//     	string ans = s.substr(a, range);
//     	char missed = s[a];

//     	while (a < s.size()) {
//     		if (t_chars.find(s[a]) == t_chars.end()) {
//     			a++;
//     			continue;
//     		}
//     		if (t_chars.find(missed) != t_chars.end() &&
//     			count[missed] < t_chars[missed]) {
//     			b++;
//     			while (b < s.size() && s[b] != missed) {
//     				if (t_chars.find(s[b]) != t_chars.end()) {
//     					count[s[b]]++;
//     				}
//     				b++;
//     			}
//     			if (b == s.size()) return ans;
//     			else count[s[b]]++;
//     		}
//     		if (b - a + 1 < range) {
//     			range = b - a + 1;
//     			ans = s.substr(a, range);
//     		}
//     		missed = s[a];
//     		count[s[a]]--;
//     		a++;
//     	}
//     	return ans;
//     }
// };

class Solution {
public:
    string minWindow(string s, string t) {
        string ans = "";
        if (s.size() < t.size()) return ans;

        // unordered_map<char, int> dict;
        vector<char> dict(256, 0);
        for (int i = 0; i < t.size(); ++i) dict[t[i]]++;

        // dict[c] > 0: requires more c
        // dict[c] < 0: has spare c
        // dict[c] ==0: has exactly sufficient c

        int count = t.size(), range = INT_MAX, l = 0, r = 0;
    	while (r < s.size()) {
    		dict[s[r]]--;
    		if (dict[s[r]] >= 0) count--;
    		r++;

    		while (dict[s[l]] < 0) {
    			dict[s[l]]++;
    			l++;
    		}
    		if (count == 0) {
    			if (r - l < range) {
    				range = r - l;
    				ans = s.substr(l, range);
    			}
    			dict[s[l]]++;
    			l++;
    			count++;
    		}
    	}
    	return ans;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	string s = "ADOBECODEBANC", t = "ABC";
	// string s = "a", t = "a";

	cout << sol.minWindow(s, t) << endl;

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