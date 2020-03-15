#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class Solution {
public:
	vector<int> countBits(int num){
		vector<int> res(1,0);
		if(num>0){
			while(res.size()<num+1){
				int len = min(res.size(),num+1-res.size());
				for(int i=0; i<len; i++){
					res.push_back(res[i]+1);
				}
			}
		}
		return res;
	}
};

int main(){
	Solution sol;
	vector<int> res = sol.countBits(12);

	for(int i=0; i<res.size(); i++){
		cout<<res[i]<<" ";
	}
}