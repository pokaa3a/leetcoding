#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;

class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        int res = 0;
        map<int, int> mp;
        stack<int> st;

        for (int i = nums.size() - 1; i >= 0; --i) {
        	int x = nums[i];
        	mp[x] = i;
        	while (!st.empty() && st.top() >= x) st.pop();
        	int less_idx = st.empty() ? nums.size() : mp[st.top()];
        	st.push(x);
        	// cout << "i: " << i << " less_idx: " << less_idx << endl;
        	res += less_idx - i;
        }
        return res;
    }
};

int main() {
	int n[] = {2,2,2};
	vector<int> nums(n, n + 3);
	Solution sol;
	cout << sol.validSubarrays(nums) << endl;
}