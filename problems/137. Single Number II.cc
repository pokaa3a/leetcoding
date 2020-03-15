#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums){
		int one=0, two=0, three=0;
		for(int i=0; i<nums.size(); i++){
			two |= one & nums[i];
			one ^= nums[i];
			three = one & two;
			one ^= three;
			two ^= three;
		}
		return one;
	}
};

int main(){
	int array[] = {2,2,2,1};
	vector<int> nums(array,array+4);

	Solution sol;
	cout<<sol.singleNumber(nums);
}