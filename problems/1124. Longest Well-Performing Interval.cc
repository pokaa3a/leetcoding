#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int longestWPI(vector<int>& hours) {
    	map<int, int> mp;
    	int sum = 0, res = 0;
    	for (int i = 0; i < hours.size(); ++i) {
    		sum += hours[i] > 8 ? 1 : -1;
    		if (sum > 0) res = max(res, i + 1);
    		else {
    			if (mp.find(sum - 1) != mp.end()) {
    				res = max(res, i - mp[sum - 1]);
    			}
    		}
    		if (mp.find(sum) == mp.end()) mp[sum] = i;
    	}
    	return res;
    }
};

int main() {
	int h[] = {9, 9, 6, 0, 6, 6, 9};
	vector<int> hours(h, h + 7);
	Solution sol;
	cout << sol.longestWPI(hours) << endl;
}