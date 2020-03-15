#include <iostream>
using namespace std;

class Solution{
public:
	int trailingZeroes(int n) {
	    int result = 0;
	    for(long i=5; n>=i; i*=5){
	    	result += n/i;
	    }
	    return result;
	}
};

int main(){

	Solution sol;
	cout<< sol.trailingZeroes(100);

}