#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int odd = 0, even = 0;
        
        for(int i=0; i<nums.size(); i++){
            if(i%2==0){
                even = max(even+nums[i], odd);
            }
            else{
                odd = max(even, odd+nums[i]);
            }
        }
        return max(odd, even);
    }
};


int main(){

	int array[] = {1,2,4,4};
	vector<int> nums(array, array+4);

	Solution sol = Solution();
	cout<<sol.rob(nums);
}