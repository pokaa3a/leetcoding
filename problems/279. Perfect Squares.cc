#include <iostream>
#include <math.h>
#include <algorithm>
#include <climits>
#include <map>
#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
	vector<int> square;
	queue<int> level;
public:
	int numSquares(int n){
		int count = 1;
		square.resize(n+1);
		level.push(0);
		while(level.size()){
			int len = level.size();
			for(int t=0; t<len; t++){
				int num = level.front();
				level.pop();
				int upper = sqrt(n-num);
				for(int k=upper; k>0; k--){
					if(num+k*k==n) return count;
					if(square[num+k*k]==0){
						level.push(num+k*k);
					}
					square[num+k*k] = count;
				}
			}
			count++;
		}
		return 0;
	}

	// int numSquares(int n){
	// 	map<int,int> square;
	// 	square[0] = 0;
	// 	for(int i=1; i<=n; i++){
	// 		int upper = sqrt(i);
	// 		int count = INT_MAX;
	// 		for(int j=1; j<=upper; j++){
	// 			count = min(square[i-j*j]+1,count);
	// 		}
	// 		square[i] = count;
	// 	}
	// 	return square[n];
	// }

	// int numSquares(int n){
	// 	int upper = sqrt(n);
	// 	int count = INT_MAX;
	// 	for(int i=upper; i>0; i--){
	// 		if(i*i==n) return 1;
	// 		count = min(count, numSquares(n-i*i)+1);
	// 	}
	// 	return count;
	// }
};


int main(){
	Solution sol;
	cout<<sol.numSquares(1535);
}