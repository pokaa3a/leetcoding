#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
private:
	vector<bool> used;
	int min_l;
	int max_l;

public:
	bool isValid(int target, int last){
		if(used[target]) return false;			// already used
		if((target+last)%2==1) return true;		// knight move or adjacent
		int mid = (target+last)/2;
		if(mid==4) return used[4];				// across [4]
		if((target%3 != last%3) && (target/3 != last/3)) return true;
		return used[mid];
	}

	int unlockNumber(int index, int num_keys){
		if(num_keys>=max_l) return 1;

		used[index] = true;
		int sum = 0;
		for(int i=0; i<9; i++){
			if(isValid(i, index)) sum += unlockNumber(i, num_keys+1);
		}
		used[index] = false;
		if(num_keys>=min_l) sum++;
		return sum;
	}

    int numberOfPatterns(int m, int n) {
    	used.resize(9);
    	min_l = m;
    	max_l = n;
    	int sum = 0;
    	sum += 4*unlockNumber(0, 1);
    	sum += 4*unlockNumber(1, 1);
    	sum += unlockNumber(4, 1);

    	return sum;
    }
};

int main(){
	Solution sol;
	cout<<sol.numberOfPatterns(1,2);
}
