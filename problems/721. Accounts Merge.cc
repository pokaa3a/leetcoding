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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<int> group(n, 0);
        for (int i = 0; i < n; i++) group[i] = i;
        
        unordered_map<string, int> mp;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                if (mp.count(accounts[i][j]) == 0) {
                    mp[accounts[i][j]] = i;
                } else {
                    uni(mp[accounts[i][j]], i, group);    
                }
            }
        }
        
        unordered_map<int, unordered_set<string>> merged_ids;
        for (int i = 0; i < n; i++) {
            int id = find(i, group);
            for (int j = 1; j < accounts[i].size(); j++) {
                if (merged_ids.count(id) == 0) merged_ids[id] = unordered_set<string>();
                merged_ids[id].insert(accounts[i][j]);
            }
        }
        vector<vector<string>> output;
        for (auto p : merged_ids) {
            output.push_back(vector<string>(1, accounts[p.first][0]));
            for (auto email : p.second) {
                output.back().push_back(email);
            }
            sort(output.back().begin() + 1, output.back().end());
        }
        return output;
    }
    int find(int x, vector<int>& group) {
        if (x != group[x]) group[x] = find(group[x], group);
        return group[x];
    }
    void uni(int x, int y, vector<int>& group) {
        int a = find(x, group);
        int b = find(y, group);
        if (a != b) group[a] = b;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	vector<vector<string>> accounts = {{"John", "johnsmith@mail.com", "john00@mail.com"}, 
									   {"John", "johnnybravo@mail.com"},
									   {"John", "johnsmith@mail.com", "john_newyork@mail.com"}, 
									   {"Mary", "mary@mail.com"}};
	sol.accountsMerge(accounts);
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