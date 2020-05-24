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
#include <list>
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
class LFUCache {
public:
    unordered_map<int, int> keyValue;
    unordered_map<int, pair<int, list<int>::iterator>> keyFreq;
    map<int, list<int>> freqKey;
    int cap;
    LFUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
    	// cout << "get: " << key << endl;
        if (!keyValue.count(key)) return -1;
        
        int val = keyValue[key];
        touch(key);
        
        return val;
    }
    
    void put(int key, int value) {
    	// cout << "put: " << key << endl;
        if (keyValue.count(key)) {
            keyValue[key] = value;
            touch(key);
        } else {
        	// new key
            if (keyValue.size() == cap) {
            	int freq_rm = freqKey.begin()->first;
                int key_rm = freqKey[freq_rm].back();
                // cout << "evicts key: " << key_rm << " freq: " << freq_rm << endl;
                freqKey[freq_rm].pop_back();
                if (freqKey[freq_rm].size() == 0) {
                	freqKey.erase(freq_rm);
                	// cout << "least freq: " << freqKey.begin()->first << endl;
                }
                keyFreq.erase(key_rm);
                keyValue.erase(key_rm);
            }
            keyValue[key] = value;
            freqKey[1].push_front(key);
            keyFreq[key] = make_pair(1, freqKey[1].begin());
        }
    }
    void touch(int key) {
    	int freq = keyFreq[key].first;
    	auto it = keyFreq[key].second;
    	keyFreq.erase(key);

    	freqKey[freq].erase(it);
    	if (freqKey[freq].size() == 0) {
    		freqKey.erase(freq);
    	}

    	freq++;
    	freqKey[freq].push_front(key);

    	keyFreq[key] = make_pair(freq, freqKey[freq].begin());
    	// cout << "touch: " << key << " freq: " << freq << endl;
    	// cout << "least freq: " << freqKey.begin()->first << endl;
    }
};

int main() {
	/* Solution */
	LFUCache lfu(2);

	lfu.put(1, 1);
	lfu.put(2, 2);
	cout << lfu.get(1) << endl;
	lfu.put(3, 3);
	cout << lfu.get(2) << endl;
	cout << lfu.get(3) << endl;
	lfu.put(4, 4);
	cout << lfu.get(1) << endl;
	cout << lfu.get(3) << endl;
	cout << lfu.get(4) << endl;

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