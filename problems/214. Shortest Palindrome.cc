#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	string shortestPalindrome(string s) {
		string reversed_str = s;
		reverse(reversed_str.begin(), reversed_str.end());
		string tmp = s + "#" + reversed_str;
		
		vector<int> table = makeTable(tmp);
		string aug_str = s.substr(table.back());
		reverse(aug_str.begin(), aug_str.end());

		return aug_str + s;
	}

	vector<int> makeTable(string s) {
		vector<int> table(s.length());

		int idx = 0;
		for (int i = 1; i < s.length(); ++i) {
			if (s[idx] == s[i]) {
				table[i] = table[i - 1] + 1;
				idx++;
			} else {
				idx = table[i - 1];

				while(idx > 0 && s[idx] != s[i]) {
					idx = table[idx - 1];
				}

				if (s[idx] == s[i]) {
					idx++;
				}
				table[i] = idx;
			}
		}
		return table;
	}
};


int main() {
	string s = "abac";

	Solution sol;
	vector<int> table = sol.makeTable(s);

	for (int i = 0; i < table.size(); ++i) {
		cout << table[i] << " ";
	}

	string p = sol.shortestPalindrome(s);
	cout << p;

}