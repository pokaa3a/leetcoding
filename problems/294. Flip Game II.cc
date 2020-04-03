#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	bool canWin(string s) {
		unordered_map<string, bool> record;
		return helper(s, record);
	}
	bool helper(string& s, unordered_map<string, bool>& record) {
		if (record.find(s) != record.end()) return record[s];

		int n = s.size();
		for (int i = 0; i < n - 1; i++) {
			if (s[i] == '+' && s[i + 1] == '+') {
				s[i] = '-';
				s[i + 1] = '-';
				if (!helper(s, record)) {
					s[i] = '+';
					s[i + 1] = '+';
					record[s] = true;
					return true;
				}
				s[i] = '+';
				s[i + 1] = '+';
			}
		}
		record[s] = false;
		return false;
	}
};

int main() {
	string s = "++++";
	Solution sol;
	cout << sol.canWin(s) << endl;
}