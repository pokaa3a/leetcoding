#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
    	for (int i = 0; i < nums.size(); ++i) {
    		if (i < nums.size() - 1) {
    			int diff = nums[i + 1] - nums[i] - 1;
    			if (k <= diff) {
    				return nums[i] + k;
    			}
    			k -= diff;
    		} else {
    			return nums[i] + k;
    		}
    	}
    	return 0;
    }
};

int main() {
	int n[] = {1,2,4};
	vector<int> nums(n, n + 3);
	int k = 3;
	Solution sol;
	cout << sol.missingElement(nums, k) << endl;
}