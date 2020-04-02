#include <iostream>
#include <string>
#include <cmath>
#include <unordered_set>
using namespace std;

class Solution {
public:  
    string crackSafe(int n, int k) {
    	string startingNode(n - 1, '0');
    	string S = "";
    	unordered_set<string> seen;
    	dfs(startingNode, k, S, seen);
    	S += startingNode;
    	return S;
    }
    void dfs(string node, int k, string& S, unordered_set<string>& seen) {
    	for (int i = 0; i < k; i++) {
    		string next = node + to_string(i);
    		if (seen.find(next) == seen.end()) {
    			seen.insert(next);
    			dfs(next.substr(1), k, S, seen);
    			S += to_string(i);
    		}
    	}
    }
};

int main() {
	Solution sol;
	int n = 2, k = 2;
	cout << sol.crackSafe(n, k) << endl;
}