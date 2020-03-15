#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	int longestConsecutive(vector<int> &nums){
		int longest = 0;
		map<int, int> range;
		for(int i = 0; i < nums.size(); i++){
			int num = nums[i];
			if(range.count(num) > 0){
				continue;
			}
			range[num] = 1;

			int head = num;
			int end = num;
			if(range.count(num+1)){
				end = num + range[num+1];
			}
			if(range.count(num-1)){
				head = num - range[num-1];
			}
			longest = max(longest, end - head + 1);
			range[end] = end - head + 1;
			range[head] = end - head + 1;
		}
		return longest;
	}
};

int main() {
	int array[] = {100,4,200,1,3,2};
	vector<int> nums(array, array+6);

	Solution sol;
	cout << sol.longestConsecutive(nums);
}