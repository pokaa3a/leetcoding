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

const int MOD = 1000000007;

/* Solution */
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
    	int n = barcodes.size();
    	map<int, int> count;
    	for (int i = 0; i < barcodes.size(); ++i) {
    		count[barcodes[i]]++;
    	}

    	map<int, vector<int> > freq;
    	for (map<int, int>::iterator it = count.begin(); it != count.end(); it++) {
    		freq[it->second].push_back(it->first);
    	}

    	vector<int> ans(barcodes.size(), 0);
    	int cur = 0;
    	for (map<int, vector<int> >::reverse_iterator it = freq.rbegin(); it != freq.rend(); ++it) {
    		int count = it->first;
    		for (int i = 0; i < it->second.size(); ++i) {
    			int code = it->second.at(i);

    			for (int k = 0; k < count; k++) {
    				int idx = cur * 2;
    				if (idx >= n) idx = idx - n + (n % 2 == 0 ? 1 : 0);
    				ans[idx] = code;
    				cur++;
    			}
    		}
    	}
    	return ans;
    }
};

int main() {
	// Solution
	Solution sol;

	// Test cases
	int b[] = {1,1,1,1,2,2,3};
	vector<int> barcodes(b, b + 7);
	vector<int> res = sol.rearrangeBarcodes(barcodes);
	for (int i = 0; i < res.size(); ++i) cout << res[i] << " ";
	cout << endl;

}