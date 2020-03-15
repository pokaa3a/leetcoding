#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <queue>
#include <stack>
#include <sstream>
#include <cmath>
using namespace std;

const int MOD = 1000000007;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* Solution */
class Solution {
public:
    int twoCitySchedCost(vector<vector<int> >& costs) {
        priority_queue<int, vector<int>, greater<int> > A;
        priority_queue<int, vector<int>, greater<int> > B;
        
        int ans = 0;
        for (int i = 0; i < costs.size(); ++i) {
        	if (costs[i][0] < costs[i][1]) {
        		ans += costs[i][0];
        		A.push(costs[i][1] - costs[i][0]);
        	} else {
        		ans += costs[i][1];
        		B.push(costs[i][0] - costs[i][1]);
        	}
        }

        int A_size = A.size(), B_size = B.size();
        while (A_size != B_size) {
        	if (A_size > B_size) {
        		int cost = A.top(); A.pop();
        		ans += cost;
        		A_size--;
        		B_size++;
        	} else {
        		int cost = B.top(); B.pop();
        		ans += cost;
        		A_size++;
        		B_size--;
        	}
        }
        return ans;
    }
};

int main() {
	// Solution
	Solution sol;

	// Test cases

}