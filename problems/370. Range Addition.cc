#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> ans(length + 1, 0);
        for (auto update : updates) {
        	ans[update[0]] += update[2];
        	ans[update[1] + 1] -= update[2]; 
        }

        for (int i = 0; i < length; i++) {
        	ans[i] += (i == 0 ? 0 : ans[i - 1]);
        }
        ans.pop_back();
        return ans;
    }
};

int main() {
	int length = 5;
	vector<vector<int>> updates = {{1,3,2}, {2,4,3}, {0,2,-2}};
	Solution sol;
	vector<int> ans = sol.getModifiedArray(length, updates);
	for (auto x : ans) cout << x << " ";
	cout << endl; 
}