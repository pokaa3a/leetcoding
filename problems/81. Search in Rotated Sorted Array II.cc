#include <iostream>
#include <vector>
using namespace std;


class Solution{
public:
	bool search(vector<int>& nums, int target){

		int left = 0, right = nums.size()-1;

		while(left <= right){
			int mid = (left + right) / 2;
			
			if(nums[mid] == target) return true;

			if(nums[left] < nums[right]){	// [1,2,3,4]
				if(nums[mid] > target){
					right = mid - 1;
				}
				else{
					left = mid + 1;
				}
			}
			else if(nums[left] > nums[right]){							// [3,4,1,2]
				if(nums[mid] < nums[left]){		// [X-o-|---X]
					if(target >= nums[left] || target < nums[mid]){
						right = mid - 1;
					}
					else{
						left = mid + 1;
					}
				}
				else{							// [X---|-o-X]
					if(target >= nums[left] && target < nums[mid]){
						right = mid - 1;
					}
					else{
						left = mid + 1;
					}
				}
			}
			else{
				do{
					left++;
				} while(right >= left && nums[left] == nums[left-1]);
			}
		}
		return false;
	}
};

int main(){
	int array[] = {1};
	int target = 3;
	vector<int> nums(array, array+1);

	Solution sol;
	cout<<sol.search(nums, target);
}