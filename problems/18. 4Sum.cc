#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution{
public:
	vector<vector<int> > fourSum(vector<int>& nums, int target){
		vector<vector<int> > res;

		sort(nums.begin(), nums.end());
		int n = nums.size();

		if(n<4) return res;

		for(int i=0; i<n-3; i++){
			if(i>0 && nums[i]==nums[i-1]) continue;
			if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3] > target) break;
			if(nums[i]+nums[n-1]+nums[n-2]+nums[n-3] < target) continue;
			for(int j=i+1; j<n-2; j++){
				if(j>i+1 && nums[j]==nums[j-1]) continue;
				if(nums[i]+nums[j]+nums[j+1]+nums[j+2] > target) break;
				if(nums[i]+nums[j]+nums[n-1]+nums[n-2] < target) continue;
				twoSum(nums, target, i, j, res);
			}
		}
		return res;
	}

	void twoSum(vector<int>& nums, int target, int i, int j, vector<vector<int> >& res){
		int left = j+1, right = nums.size()-1;
		while(left < right){
			if(nums[i]+nums[j]+nums[left]+nums[right] < target){
				do{left++;} while(left<right && nums[left]==nums[left-1]);
			}
			else if(nums[i]+nums[j]+nums[left]+nums[right] > target){
				do{right--;} while(left<right && nums[right]==nums[right+1]);
			}
			else{
				vector<int> vec;
				vec.push_back(nums[i]);
				vec.push_back(nums[j]);
				vec.push_back(nums[left]);
				vec.push_back(nums[right]);
				res.push_back(vec);
				do{left++;} while(left<right && nums[left]==nums[left-1]);
				do{right--;} while(left<right && nums[right]==nums[right+1]);
			}
		}
	}
};

int main(){

	int array[] = {0,0,0,0};
	vector<int> nums(array, array+4);

	int target = 0;

	Solution sol;
	vector<vector<int> > res = sol.fourSum(nums, target);

	for(int i=0; i<res.size(); i++){
		for(int j=0; j<res[i].size(); j++){
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}

}