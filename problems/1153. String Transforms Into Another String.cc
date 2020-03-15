#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
	bool canConvert(string str1, string str2) {
		if (str1 == str2) return true;
		map<char, char> transform;
		for (int i = 0; i < str1.length(); ++i) {
			if (transform.find(str1[i]) != transform.end() && transform[str1[i]] != str2[i]) {
				return false;
			}
			transform[str1[i]] = str2[i];
		}
		set<char> s;
		for (int i = 0; i < str2.length(); ++i) {
			s.insert(str2[i]);
		}
		return s.size() < 26;
	}
};

int main() {
	string str1 = "aabcc";
	string str2 = "ccdee";
	Solution sol;
	cout << sol.canConvert(str1, str2) << endl;
}