#include <iostream>
#include <vector>
using namespace std;

// class Solution{
// public:
// 	int numTrees(int n) {
// 		num_trees_ = vector<int>(n+1, 0);
// 		num_trees_[0] = 1;
// 		num_trees_[1] = 1;
// 		return helper(n);
// 	}

// 	int helper(int n) {
// 		if(num_trees_[n] == 0){
// 			int num = 0;
// 			for (int i = 0; i < n/2; ++i) {
// 				num += helper(i) * helper(n-1-i);
// 			}
// 			num *= 2;
// 			if(n%2 != 0) {
// 				num += helper(n/2) * helper(n/2);
// 			}
// 			num_trees_[n] = num;
// 		}
// 		return num_trees_[n];
// 	}

// private:
// 	vector<int> num_trees_;
// };

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        
        for (int i = 1; i <= n; ++i) {
            for (int k = 1; k <= i; ++k) {
                dp[i] += dp[k - 1] * dp[i - k];
            }
        }
        return dp[n];
    }
};

int main() {
	Solution sol;
	cout << sol.numTrees(4);
}