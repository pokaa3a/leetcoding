#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	void headRange(vector<string>& res, long lower, long first){
		if(first==lower+1){
			res.push_back(to_string(lower));
		}
		else if(first>lower+1){
			res.push_back(to_string(lower)+"->"+to_string(first-1));
		}
	}
	void range(vector<string>& res, long lower, long upper){
		if(upper == lower+2){
			res.push_back(to_string(lower+1));
		}
		else if(upper > lower+2){
			res.push_back(to_string(lower+1)+"->"+to_string(upper-1));
		}
	}
	void tailRange(vector<string>& res, long last, long upper){
		if(last==upper-1){
			res.push_back(to_string(upper));
		}
		else if(last<upper-1){
			res.push_back(to_string(last+1)+"->"+to_string(upper));
		}
	}

    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        if(nums.size()==0){
        	if(lower==upper) res.push_back(to_string(lower));
        	else res.push_back(to_string(lower)+"->"+to_string(upper));
        }
        else{
        	headRange(res, lower, nums[0]);
        	for(int i=0; i<nums.size()-1; i++){
        		range(res, nums[i], nums[i+1]);
        	}
        	tailRange(res, nums[nums.size()-1], upper );
        }
        return res;
    }
};


int main(){
	int array[] = {2147483647};
	vector<int> nums(array, array+1);
	int lower=2147483647, upper=2147483647;

	Solution sol;
	vector<string> res = sol.findMissingRanges(nums, lower, upper);
	for(int i=0; i<res.size(); i++){
		cout<<res[i]<<endl;
	}

}