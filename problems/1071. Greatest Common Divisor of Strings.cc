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
    string gcdOfStrings(string str1, string str2) {
        string S1 = str1.size() < str2.size() ? str1 : str2;
        string S2 = str1.size() < str2.size() ? str2 : str1;

        for (int i = S1.size(); i >= 1; --i) {
        	if (S1.size() % i != 0 || S2.size() % i != 0) continue;
        	if (canBeDivided(S1.substr(0, i), S1) &&
        		canBeDivided(S1.substr(0, i), S2)) return S1.substr(0, i);
        }
    	return "";
    }
    bool canBeDivided(string T, string S) {
    	// cout << "T: " << T << " S: " << S << endl;
    	int len = T.size();
    	if (S.size() % len != 0) return false;
    	for (int i = 0; i < S.size(); i += len) {
    		if (S.substr(i, len) != T) return false;
    	}
    	return true;
    }
};

int main() {
	// Solution
	Solution sol;

	// Test cases
	string str1 = "NLZGMNLZGMNLZGMNLZGMNLZGMNLZGMNLZGMNLZGM";
	string str2 = "NLZGMNLZGMNLZGMNLZGMNLZGMNLZGMNLZGMNLZGMNLZGM";
	cout << sol.gcdOfStrings(str1, str2) << endl;
}