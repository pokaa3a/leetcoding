#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	bool backspaceCompare(string S, string T) {
		string s = "", t = "";
		for (int i = 0; i < S.length(); ++i) {
			if (S[i] == '#') {
				if (s.length() > 0)
					s = s.substr(0, s.length() - 1);
			} else {
				s += S[i];
			}
		}
		for (int i = 0; i < T.length(); ++i) {
			if (T[i] == '#') {
				if (t.length() > 0)
					t = t.substr(0, t.length() - 1);
			} else {
				t += T[i];
			}
		}
		// cout << "s: " << s << endl;
		// cout << "t: " << t << endl;
		return s == t;
	}
};

int main() {
	string S = "#####b";
	string T = "b";
	Solution sol;
	cout << sol.backspaceCompare(S, T) << endl;
}