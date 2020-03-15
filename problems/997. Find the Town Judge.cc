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
    int findJudge(int N, vector<vector<int> >& trust) {
        if (N == 1) return 1;
        
        map<int, int> people_trust_you;
        map<int, int> you_trust_people;

        for (int i = 0; i < trust.size(); ++i) {
        	you_trust_people[trust[i][0]]++;
        	people_trust_you[trust[i][1]]++;
        }

        for (map<int, int>::iterator it = people_trust_you.begin(); it != people_trust_you.end(); ++it) {
        	if (it->second == N - 1) {
        		if (you_trust_people[it->first] == 0) return it->first;
        		else return -1;
        	}
        }
        return -1;
    }
};

int main() {
	// Solution
	Solution sol;

	// Test cases


}