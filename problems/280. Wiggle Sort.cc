#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
    	if(nums.size()==0) return;
        for(int i=0; i<nums.size()-1; i++){
        	if((i%2==0 && nums[i]>nums[i+1]) || (i%2==1 && nums[i]<nums[i+1])){
        		swap(nums[i], nums[i+1]);
        	}
        }
    }
};

int main(){
	int array[] = {3,5,2,1,6,4};
	vector<int> nums(array, array+6);
	Solution sol;
	sol.wiggleSort(nums);
	for(int i=0; i<nums.size(); i++){
		cout<<nums[i]<<" ";
	}
}