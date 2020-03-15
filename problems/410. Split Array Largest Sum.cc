#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
    	long total = 0, maximum = 0;
    	for (int i = 0; i < nums.size(); ++i) {
    		maximum = max((int)maximum, nums[i]);
    		total += nums[i];
    	}

    	long left = max(maximum, total / m);
    	long right = total;

    	while (left < right) {
    		long mid = (left + right) / 2;
    		int n = split(nums, mid);

    		if (n <= m) {
    			right = mid;
    		} else {
    			left = mid + 1;
    		}
    	}
    	return left;
    }
    
    int split(vector<int>& nums, int sum){
    	long cnt = 0;
    	int parts = 1;
    	for (int i = 0; i < nums.size(); ++i) {
    		cnt += nums[i];
    		if (cnt > sum) {
    			cnt = nums[i];
    			parts++;
    		}
    	}
    	return parts;
    }
};

int main() {
	int array[] = {7, 2, 5, 10, 8};
	vector<int> nums(array, array + 5);
	Solution sol;
	int m = 2;
	cout << sol.splitArray(nums, m) << endl;
}