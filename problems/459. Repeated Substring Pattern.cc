#include <iostream>
using namespace std;

class Solution {
public:
	bool repeatedSubstringPattern(string s) {
		int n = s.size();
		for (int len = 1; len <= n / 2; len++) {
			string str = s.substr(0, len);
			if (n % len == 0) {
				int k = len;
				bool valid = true;
				while (k < n) {
					if (s.find(str, k) != k) {
						valid = false;
						break;
					}
					k += len;
				}
				if (valid) return true;
			}
		}
		return false;
	}
};

int main() {
	string s = "abcabcabc";
	Solution sol;
	cout << sol.repeatedSubstringPattern(s) << endl;
}