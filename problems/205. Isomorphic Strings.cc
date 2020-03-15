#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	bool isIsomorphic(string s, string t) {
		vector<int> vec1(128, -1);
		vector<int> vec2(128, -1);

		for (int i = 0; i < s.length(); ++i) {
			if (vec1[s[i]] != vec2[t[i]]) return false;
			vec1[s[i]] = i;
			vec2[t[i]] = i;
		}
		return true;
	}
};

int main() {
	string s = "egg";
	string t = "add";

	Solution sol;
	cout << sol.isIsomorphic(s, t);
}