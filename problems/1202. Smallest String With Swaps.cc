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
    string smallestStringWithSwaps(string s, vector<vector<int> >& pairs) {
        int n = s.size();
        vector<int> group(n + 1, 0);
        for (int i = 0; i < n; ++i) group[i] = i;

        for (int i = 0; i < pairs.size(); ++i) {
        	int x = find(pairs[i][0], group);
        	int y = find(pairs[i][1], group);
        	if (x != y) {
        		group[y] = x;
        	}
        }

        map<int, vector<int> > idx_group;
        map<int, vector<char> > str_group;
        for (int i = 0; i < n; ++i) {
        	int g = find(i, group);
        	// cout << "g: " << g << endl;
        	if (idx_group.find(g) == idx_group.end()) {
        		idx_group[g] = vector<int>();
        		str_group[g] = vector<char>();
        	}
        	// cout << " i = " << i << " s[i] = " << s[i] << endl;
        	idx_group[g].push_back(i);
        	str_group[g].push_back(s[i]);
        }

        for (map<int, vector<int> >::iterator it = idx_group.begin(); it != idx_group.end(); ++it) {
        	int g = it->first;
        	vector<int> idx = idx_group[g];
        	vector<char> str = str_group[g];
        	sort(str.begin(), str.end());
        	for (int k = 0; k < idx.size(); ++k) {
        		s[idx[k]] = str[k];
        	}
        }
        return s;
    }
    int find(int x, vector<int>& group) {
    	if (x != group[x]) group[x] = find(group[x], group);
    	return group[x];
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
	const int rows = 2;
	const int cols = 2;
	int arr[rows][cols] = {{0, 3}, {1, 2}};
	vector<vector<int> > grid;
	for (int r = 0; r < rows; ++r) {
		grid.push_back(vector<int>(arr[r], arr[r] + cols));
	}
	string s = "dcab";
	cout << sol.smallestStringWithSwaps(s, grid) << endl;

	/* [String] */
	// string str = "";

}