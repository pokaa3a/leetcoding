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
    vector<string> beforeAndAfterPuzzles(vector<string>& phrases) {
        map<string, vector<pair<int, string> > > mp;
        set<string> added;
        for (int i = 0; i < phrases.size(); ++i) {
        	vector<string> split = first_word(phrases[i]);
        	if (mp.find(split[0]) == mp.end()) {
        		mp[split[0]] = vector<pair<int, string> >();
        	}
        	mp[split[0]].push_back(make_pair(i, split[1]));
        }
        vector<string> ans;
        for (int i = 0; i < phrases.size(); ++i) {
        	vector<string> split = last_word(phrases[i]);
        	if (mp.find(split[0]) != mp.end()) {
        		// cout << "split[0] = " << split[0] << endl;
        		for (int j = 0; j < mp[split[0]].size(); ++j) {
        			pair<int, string> p = mp[split[0]][j];
        			// cout << "p.first = " << p.first << endl;
        			if (i == p.first) continue;
        			string to_add = split[1] + (split[1] == "" ? "" : " ") + split[0] + (p.second == "" ? "" : " " + p.second);
        			// cout << "to_add: " << to_add << endl;
        			if (added.count(to_add) == 0) {
        				ans.push_back(to_add);
        				added.insert(to_add);
        			}
        		}
        	}
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
    vector<string> first_word(string phrase) {
    	vector<string> ans(2, "");
    	int i = phrase.find(" ");
    	if (i == string::npos) {
    		ans[0] = phrase;
    		ans[1] = "";
    	} else {
    	ans[0] = phrase.substr(0, i);
    	ans[1] = phrase.substr(i + 1);
    }
    	return ans;
    }
    vector<string> last_word(string phrase) {
    	string r_phrase = phrase;
    	reverse(r_phrase.begin(), r_phrase.end());
    	vector<string> ans = first_word(r_phrase);
    	reverse(ans[0].begin(), ans[0].end());
    	reverse(ans[1].begin(), ans[1].end());
    	return ans;
    }
};


int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	vector<string> phrases;
	phrases.push_back("a");
	phrases.push_back("b");
	phrases.push_back("a");
	// phrases.push_back("chocolate bar");
	// phrases.push_back("mission impossible");
	// phrases.push_back("a man on a mission");
	// phrases.push_back("block party");
	// phrases.push_back("eat my words");
	// phrases.push_back("bar of soap");
	vector<string> ans = sol.beforeAndAfterPuzzles(phrases);
	for (int i = 0; i < ans.size(); ++i) cout << ans[i] << endl;


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