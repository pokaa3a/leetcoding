#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k){
		map<int, int> dict;
		for(int i=0; i<nums.size(); i++){
			if(dict.find(nums[i])==dict.end()){
				dict[nums[i]] = i;
			}
			else{
				if(i-dict[nums[i]]<=k) return true;
				else dict[nums[i]] = i;
			}
		}
		return false;
	}
};

int main(){
	int array[] = {1,2,3,4,5,9,6,7,2};
	vector<int> nums(array,array+9);

	Solution sol;
	cout<<sol.containsNearbyDuplicate(nums, 5);

}