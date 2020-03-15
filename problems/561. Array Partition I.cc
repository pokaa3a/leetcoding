#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int arrayPairSum(vector<int>& nums){
		sort(nums.begin(), nums.begin()+nums.size());
		int sum = 0;
		for(int i=0; i<nums.size(); i+=2){
			sum += nums[i];
		}
		return sum;
	}
};

int main(){
	int array[] = {1,4,3,2};
	vector<int> nums(array,array+4);

	Solution sol;
	cout<<sol.arrayPairSum(nums);
}