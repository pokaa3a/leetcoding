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
class AllOne {
public:
    unordered_map<string, int> key_val;
    map<int, unordered_set<string>> val_keys;
    int max_val, min_val;
    /** Initialize your data structure here. */
    AllOne() {
        max_val = 0;
        min_val = 0;
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
    	cout << "inc " << key << endl;

        key_val[key]++;
        if (key_val[key] == 1) {
            // new key
            val_keys[1].insert(key);
            min_val = 1;
        } else {
            // move from val - 1 to val
            val_keys[key_val[key] - 1].erase(key);
            val_keys[key_val[key]].insert(key);
        }
        max_val = max(max_val, key_val[key]);
        if (val_keys.find(min_val) == val_keys.end() || val_keys[min_val].size() == 0) {
            min_val = key_val[key];
        }
    	cout << "max val: " << max_val << endl;
    	cout << "min val: " << min_val << endl;
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
    	cout << "dec " << key << endl;
        if (key_val.find(key) == key_val.end() || key_val[key] == 0) return;    // key does not exit
        
        key_val[key]--;
        val_keys[key_val[key] + 1].erase(key);
        if (key_val[key] > 0) {
            val_keys[key_val[key]].insert(key);
            min_val = min(min_val, key_val[key]);
        }
        
        if (val_keys.find(max_val) == val_keys.end() || val_keys[max_val].size() == 0) {
            max_val = key_val[key];
        }
    	cout << "max val: " << max_val << endl;
    	cout << "min val: " << min_val << endl;
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if (max_val == 0) return "";
        return *val_keys[max_val].begin();
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if (max_val == 0) return "";
        return *val_keys[min_val].begin();
    }
};



int main() {
	/* Solution */
	AllOne ao;
	ao.inc("a");
	ao.inc("b");
	ao.inc("b");
	ao.inc("c");
	ao.inc("c");
	ao.inc("c");
	ao.dec("b");
	ao.dec("b");
	cout << ao.getMinKey() << endl;
	ao.dec("a");
	cout << ao.getMaxKey() << endl;
	cout << ao.getMinKey() << endl;

	/* Test cases */

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