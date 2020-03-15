#include <iostream>
#include <vector>
using namespace std;

// class Solution {
// public:
// 	int movesToMakeZigzag(vector<int>& nums) {
// 		int res1 = 0, res2 = 0;
// 		for (int i = 1; i < nums.size(); i += 2) {
// 			if (i == nums.size() - 1) {
// 				res1 += nums[i - 1] > nums[i] ? 0 : nums[i] - nums[i - 1] + 1; 
// 			} else {
// 				int d1 = nums[i - 1] > nums[i] ? 0 : nums[i] - nums[i - 1] + 1;
// 				int d2 = nums[i + 1] > nums[i] ? 0 : nums[i] - nums[i + 1] + 1;
// 				res1 += max(d1, d2);
// 			}
// 		}
// 		for (int i = 0; i < nums.size(); i += 2) {
// 			if (i == nums.size() - 1) {
// 				res2 += nums[i - 1] > nums[i] ? 0 : nums[i] - nums[i - 1] + 1;
// 			} else if (i == 0) {
// 				res2 += nums[i + 1] > nums[i] ? 0 : nums[i] - nums[i + 1] + 1;
// 			} else {
// 				int d1 = nums[i - 1] > nums[i] ? 0 : nums[i] - nums[i - 1] + 1;
// 				int d2 = nums[i + 1] > nums[i] ? 0 : nums[i] - nums[i + 1] + 1;
// 				res2 += max(d1, d2);
// 			}
// 		}
// 		return min(res1, res2);
// 	}
// };

class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int n = nums.size();
        int ans0 = 0, ans1 = 0;
        
        vector<int> copy_num = nums;

        for (int i = 0; i < n - 1; i++) {
            if (i % 2 == 0) {
                if (nums[i] > nums[i + 1]) continue;
                else {
                    ans0 += nums[i + 1] - nums[i] + 1;
                    nums[i + 1] = nums[i] - 1;
                }
            } else {
                if (nums[i] < nums[i + 1]) continue;
                else {
                    ans0 += nums[i] - nums[i + 1] + 1;
                    nums[i] = nums[i + 1] - 1;
                }
            }
        }
        
        for (int i = 0; i < n - 1; i++) {
            if (i % 2 == 0) {
                if (copy_num[i] < copy_num[i + 1]) continue;
                else {
                    ans1 += copy_num[i] - copy_num[i + 1] + 1;
                    copy_num[i] = copy_num[i + 1] - 1;
                }
            } else {
                if (copy_num[i] > copy_num[i + 1]) continue;
                else {
                    ans1 += copy_num[i + 1] - copy_num[i] + 1;
                    copy_num[i + 1] = copy_num[i] - 1;
                }
            }
        }
        return min(ans0, ans1);
    }
};

int main() {
	int n[] = {9, 6, 1, 6, 2};
	vector<int> nums(n, n + 5);
	Solution sol;
	cout << sol.movesToMakeZigzag(nums) << endl;
}