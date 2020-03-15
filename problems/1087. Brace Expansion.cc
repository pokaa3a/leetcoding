#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	void expand(string S) {
		vector<vector<bool> > dict;
		vector<bool> temp(26, false);

		bool in_brace = false;
		for (int i = 0; i < S.length(); ++i) {
			if (S[i] == '{') {
				in_brace = true;
				dict.push_back(temp);
				continue;
			} else if (S[i] == '}') {
				in_brace = false;
				continue;
			}
			if (S[i] == ',') continue;
			if (in_brace) {
				dict.back()[S[i] - 'a'] = true;
			} else {
				dict.push_back(temp);
				dict.back()[S[i] - 'a'] = true;
			}
		}
		
		

	}
};

int main() {
	string S = "{a,b}c{d,e}f";
	Solution sol;
	sol.expand(S);
}