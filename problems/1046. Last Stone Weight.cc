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

/* Solution */
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        while (pq.size() > 1) {
        	int a = pq.top(); pq.pop();
        	int b = pq.top(); pq.pop();
       		int res = abs(a - b);
       		if (res > 0) pq.push(res);
        }
        if (pq.size() == 0) return 0;
        return pq.top(); 
    }
};

int main() {
	// Solution
	Solution sol;

	// Test cases

}