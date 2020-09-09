#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int firstMissingPositive(vector<int>& nums) {
    bool hasOne = false;
    int n = nums.size();
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 1) hasOne = true;
      else if (nums[i] < 1 || nums[i] > n) {
        nums[i] = 1;
      }
    }
    if (!hasOne) return 1;
    
    for (int i = 0; i < n; i++) {
      nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1]);
    }
    for (int i = 0; i < n; i++) {
      if (nums[i] > 0) return i + 1;
    }
    return n + 1;
  }
};

int main() {
	vector<int> nums = {1,2,8,9,11,12,4,5};
	Solution sol;
	cout << sol.firstMissingPositive(nums) << endl;
}