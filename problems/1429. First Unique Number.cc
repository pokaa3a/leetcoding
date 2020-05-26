#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <queue>
#include <stack>
#include <list>
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
class FirstUnique {
public:
    list<int> uniq;
    unordered_map<int, list<int>::iterator> mp;
    FirstUnique(vector<int>& nums) {
        for (auto x : nums) {
            if (mp.count(x) == 0) {
                uniq.push_back(x);
                mp[x] = prev(uniq.end());
            } else {
            	if (mp[x] != uniq.end()) {
            		uniq.erase(mp[x]);
            		mp[x] = uniq.end();
            	}
            }
        }
    }
    
    int showFirstUnique() {
        if (uniq.empty()) return -1;
        return uniq.front();
    }
    
    void add(int value) {
        if (mp.count(value) == 0) {
            uniq.push_back(value);
            mp[value] = prev(uniq.end());
        } else {
        	if (mp[value] != uniq.end()) {
        		uniq.erase(mp[value]);
        		mp[value] = uniq.end();
        	}
        }
    }
};

int main() {
	/* Solution */
	vector<int> nums = {7,7,7,7,7,7};
	FirstUnique q(nums);

	/* Test cases */
	q.add(7);
	q.add(3);
	q.add(3);
	q.add(7);
	q.add(17);
	cout << q.showFirstUnique() << endl;

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